#include <iostream>
#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
#include <boost/circular_buffer.hpp>
#include <Eigen/Eigen>
#include "kalman_filter.h"
#include <bits/stdc++.h>

using namespace cv;
ros::Subscriber distance_sub;
ros::Publisher pose_pub;
ros::Subscriber image_sub;

//useless
ros::Publisher vision_pose_pub;

ros::Publisher dlio_pose_pub;
ros::Subscriber dlio_imu_sub;
ros::Subscriber dlio_odom_sub;
ros::Subscriber dlio_shift_sub;
ros::Publisher optical_pose_pub;

//用完就删


cv::Mat pre_image;  //上一帧图像
std::vector<cv::Point2f> p0; //上一帧特征点
cv::Mat mask;   //遮罩
cv::Point2f velocity(0.0f, 0.0f); //光流速度s
cv::Point2f last_velocity(0.0f, 0.0f);
cv::Point2f last_average;


Point2f pose (0.0f, 0.0f);

Eigen::Vector3f gravity_vec(0.0f, 0.0f, 9.80665f);
Eigen::Quaternionf orientation_value;

float lambda = 1.13f;
// static constexpr uint8_t kFilterWindowSize = 3;
//640*480camera
// static constexpr float f_x = 1836.6687;
// static constexpr float f_y = 1836.6687;

//1280*960
//校外会议室标定
// static constexpr float f_x = 2168.6687;
// static constexpr float f_y = 2168.6687;
// float f_x = 2012.6687;
// float f_y = 2012.6687;
//最开始标定
// float f_x = 1068.08166;
// float f_y = 1068.08166;
float f_x = 1008.08166;
float f_y = 1008.08166;

//640*480camera
//18.14 repsents 1 m / s in normalization_space
// static constexpr float max_pixel_per_frame = 18;

// 1280*960camera
// 31.2 repsents 1 m / s in normalization_space
// float max_pixel_per_frame = 31.2;

// 18.72 repsents 0.6 m / s in normalization_space
float max_pixel_per_frame = 18.72;

static const int micrometer_to_meter = 1000000;

static const int stop_threshold = 30;

//filter
int window_size_x = 2;
int window_size_vel = 10;
std::vector<float> filter_buffer_x;
std::vector<float> filter_buffer_vel;

float global_x = 0.0f;
int stop_img_count = 0; //record stop image num
bool stop_flag = false; //uav stop

//dlio message
static constexpr float gravity = 9.80665f;
//livox imu buffer
boost::circular_buffer<sensor_msgs::Imu> imu_buffer(200);
//dlio velocity
Eigen::Vector3f dlio_velocity;

//dlio pose
Eigen::Vector3f dlio_pose_msg;

//pitch
float pitch = 0.0f;

//flags
//first image flag
bool first_image = true;

//记得默认true
//turn on optical flow
bool opt_flow_off = true;

//image time record
ros::Time last_time;
ros::Time cur_time;

//kalman_filter
KalmanFilter_1 kf_x;
KalmanFilter_1 kf_y;

//matrix
std::vector<float> P0,Q0,R0;
//average filter fuction, filter x distance per image frame
float AverageFilter(float original_data, std::vector<float> & filter_buffer, int window_size) {

    //return original data while the first window_size data comes
    float sum = original_data;
    
    if(filter_buffer.size() < window_size) {
        filter_buffer.push_back(original_data);
        return original_data;
    } 
    //return data after average filter
    else if (filter_buffer.size() == window_size) {
        for(int i = 0; i < window_size - 1; i++) {
            sum += filter_buffer[i];
            filter_buffer[i] = filter_buffer[i + 1];
        }
        filter_buffer[window_size - 1] = original_data;
        return (sum / window_size);
    }

}

void lidar_callback(const std_msgs::Float32::ConstPtr& msg) {
    lambda = abs(msg->data);
    // std::cout << "lambda=" << lambda << std::endl;
}

void image_receive_callback(cv::Mat frame, Eigen::Vector3f& imu_acc, float time_dif, bool imu_flag){
    cv::Mat cur_image;
    cv::Point2f average = Point2f(0.0f, 0.0f);
    cv::Point2f pixel_sum(0.0f, 0.0f);
    cv::Point2f distance_dif(0.0f, 0.0f);
    cv::Point2f normalization_space(0.0f, 0.0f);
    cv::cvtColor(frame, cur_image, cv::COLOR_RGB2GRAY);
    // if(pre_image.empty()){
    //     std::cout << "pre_image is empty" << std::endl;
    //     pre_image=cur_image;
    //     return;
    // }

    // cv::goodFeaturesToTrack(pre_image,p0,100,0.3,7,mask,7,false,0.04);     // 检测上一帧的特征点
    cv::goodFeaturesToTrack(pre_image,p0,100,0.1,10,mask,7);     // 检测上一帧的特征点
    if (p0.size() == 0) {
        pre_image = cur_image;
        return;
    }
    std::vector<cv::Point2f>p1;
    std::vector<uchar> status;
    std::vector<float> err;
    cv::TermCriteria criteria=cv::TermCriteria((cv::TermCriteria::COUNT)+(cv::TermCriteria::EPS),10,0.03);
    cv::calcOpticalFlowPyrLK(pre_image,cur_image,p0,p1,status,err,cv::Size(15,15),2,criteria);

    std::vector<cv::Point2f> good_point;

    pre_image=cur_image;
    // cv::cvtColor(cur_image,cur_image,cv::COLOR_GRAY2RGB);
    int count = 0;
    int bad_point_count = 0;
    for(int i=0;i<p0.size();i++){
        if(status[i]==1){
            good_point.push_back(p1[i]);
            float delt_x = (p1[i].x - p0[i].x);
            float delt_y =  (p1[i].y - p0[i].y);
            if (cv::norm(p1[i] - p0[i]) > (max_pixel_per_frame / lambda)) {
                continue;
            }
            if (abs(delt_x) < 1 && abs(delt_y) < 1) continue; //filter
            if (abs(delt_x > (max_pixel_per_frame / lambda)) || abs(delt_y > (max_pixel_per_frame / lambda))) {
                bad_point_count++;
                continue;
            }
            // std::cout << "delt_x =  " << delt_x << std::endl;
            pixel_sum.x +=  delt_x;
            pixel_sum.y += delt_y;
            count ++;
            // cv::circle(cur_image,p1[i],2,cv::Scalar(255,0,0),1);
            // cv::line(cur_image,p0[i],p1[i],cv::Scalar(0,255,0));
            // cv::imshow("get", cur_image);
            // cv::waitKey(1);
            // cv::arrowedLine(cur_image,p0[i],p1[i],cv::Scalar(255,0,0),1);
        }
    }
    float pixelx_lastframe = ((velocity.x * time_dif) * micrometer_to_meter) / lambda / f_x;
    // std::cout << "lambda = " << lambda << std::endl;
    switch (count)
    {
    case 0:
        ROS_ERROR("0 point ------------------");
        // average = Point2f(0.0f, 0.0f);
        // last_average = average;
        stop_img_count++;
        if (stop_img_count > stop_threshold) {
            stop_flag = true;
            velocity = Point2f(0.0f, 0.0f);
            last_velocity = velocity;
            average = Point2f(0.0f, 0.0f);
            std::cout << "!!!!!!!!!!!! UAV stop !!!!!!!!!!!!!!!!!!!!!!\n";
            std::cout << "stop_img_count: " << stop_img_count << std::endl;
        } else {
            average = last_average * 0.7 + Point2f(pixelx_lastframe, 0) * 0.3;
        }
        // std::cout << "average x: " << average.x << std::endl;
        last_average = average;
        break;
    case 1:
        ROS_ERROR("1 point ------------------");
        // average = Point2f(0.0f, 0.0f);
        // last_average = average;
        // // break;
        if(last_average.x == 0.0f) {
            average = cv::Point2f(0.0f, 0.0f);
        } else {
            average = last_average * 0.7 + Point2f(pixelx_lastframe, 0) * 0.3;
        }
        // std::cout << "average x: " << average.x << std::endl;
        last_average = average;
        stop_img_count = 0;
        stop_flag = false;
        break;
    default:
        average = pixel_sum / count;
        // std::cout << "average x: " << average.x << std::endl;
        last_average = average;
        stop_img_count = 0;
        stop_flag =false;
        break;
    }
    average.x = AverageFilter(average.x, filter_buffer_x, window_size_x);
    average.y = AverageFilter(average.y, filter_buffer_vel, window_size_x);
    //um,10e-6m
    normalization_space.x = average.x * f_x;
    normalization_space.y = average.y * f_y;
    //m
    distance_dif = (normalization_space * lambda) / micrometer_to_meter;
    if(abs(pitch) < 20) {

    }
    velocity.x = distance_dif.x / time_dif;
    velocity.x = AverageFilter(velocity.x, filter_buffer_vel, window_size_vel);
    pose += distance_dif;
    if (imu_flag == true) { //kalman filter
        switch (count)
        {
        case 0 :
            if(stop_flag == true) { //静止
                std::cout << "-----------------uav stop---------------------\n";
                kf_x.X(1) = 0.0f; // 速度0，位置不变
            } else { //运动中，图像某一帧光流失败
                // pose.x += velocity.x * time_dif + 0.5 * imu_acc.x() * time_dif * time_dif;
                kf_x.process(time_dif, imu_acc.x(), pose.x, velocity.x);
            }
            break;
        case 1 :
            kf_x.process(time_dif, imu_acc.x(), pose.x, velocity.x);
            break;
        default:
            kf_x.process(time_dif, imu_acc.x(), pose.x, velocity.x);
            break;
        }
    } else {
        ROS_ERROR("imu_flag is false");
    }

    //记得注释回来
    printf("\033[2J\033[1;1H");
    std::cout << "opitcal_pose: " <<  pose.x << std::endl;
    std::cout << "velocity: " << velocity.x << std::endl;
    geometry_msgs::Vector3 optical_pose;
    optical_pose.x = pose.x;
    optical_pose_pub.publish(optical_pose);

    // geometry_msgs::Pose pose_pub;
    // pose_pub.position.x = pose.x;
    // // pose_pub.position.y = dlio_pose_msg.x();
    // // pose_pub.position.z = dlio_pose_msg.y();
    // // pose_pub.orientation.x = dlio_velocity(0);
    // // pose_pub.orientation.y = velocity.x;
    // dlio_pose_pub.publish(pose_pub);

    // cv::arrowedLine(cur_image,Point2f(200.0f, 200.0f), average + Point2f(200.0f, 200.0f),cv::Scalar(255,0,0), 5);
    // sensor_msgs::ImagePtr output_image=cv_bridge::CvImage(std_msgs::Header(),"rgb8",cur_image).toImageMsg();
    // cv::imshow("dst",cur_image );
    // cv::waitKey(1);
    p0=good_point;
    // std::cout<<"   追踪到的特征点："<<good_point.size()<<"   失败的点数量: "<<p0.size()-good_point.size()<<std::endl;
}
bool cul_imu(ros::Time last_time, ros::Time cur_time, Eigen::Vector3f &imu_acc){
    if (imu_buffer.empty() || imu_buffer.front().header.stamp < cur_time) {
        return false;
    }
    auto imu_it = imu_buffer.begin();
    auto last_imu_it = imu_it;
    int num = 0;
    while (imu_it != imu_buffer.end() && imu_it->header.stamp >= cur_time) {
        num++;
        last_imu_it = imu_it;
        imu_it++;
    }
    if (imu_it == imu_buffer.end()) { //没有旧的imu数据
        std::cout << "no old imu data\n";
        return false;
    }
    int count = 0;
    for(auto it = last_imu_it; it != imu_buffer.end() && it->header.stamp >= last_time; it++) {

        imu_acc(0) += it->linear_acceleration.x;
        imu_acc(1) += it->linear_acceleration.y;
        imu_acc(2) += it->linear_acceleration.z;
        count++;
    }
    if (count == 0) {
        return false;
    }
    imu_acc /= count;
    return true;
}
void image_callback(const sensor_msgs::ImageConstPtr msg ){
    // std::cout << "imagr callback" <<std::endl;
    if (opt_flow_off == true) {
        // std::cout<<"iiiiiiiiiiiiiiiiiiiii"<<std::endl;
        if(!pre_image.empty()) {
            pre_image.release();
        }
        if (first_image == false) {
            first_image = true;
        }
        if (!filter_buffer_x.empty()) {
            filter_buffer_x.clear();
        }
        if (!filter_buffer_vel.empty()) {
            filter_buffer_vel.clear();
        }
        if (velocity.x != 0.0f) {
            velocity = cv::Point2f(0.0f,0.0f);
        }
        if (last_average.x != 0.0f) {
            last_average = cv::Point2f(0.0f,0.0f);
        }
        if (last_average.x != 0.0f) {
            last_average = cv::Point2f(0.0f,0.0f);
        }
        if (pose.x != 0.0f) {
            pose = cv::Point2f(0.0f,0.0f);
        }
        if (stop_img_count != 0) {
            stop_img_count = 0;
        }
        if (stop_flag != false) {
            stop_flag = false;
        }
        return;
    }
    Eigen::Vector3f imu_acc(0.0,0.0,0.0);
    bool res = false;
    double time_dif = 0.0;
    cv_bridge::CvImageConstPtr img_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::RGB8);
    if(!first_image) {  
        cur_time = msg->header.stamp;
        time_dif = (cur_time - last_time).toSec();
        res = cul_imu(last_time, cur_time, imu_acc);
        last_time = cur_time;
        if(res == false) {
            std::cout <<"buffer no imu data between image"<<std::endl;
        }
        if (time_dif <= 0) {
            ROS_ERROR("------------time_dif------------ < 0");
            return;
        }
        image_receive_callback(img_ptr->image, imu_acc, time_dif,res);
    } else {
        first_image = false;
        last_time = msg->header.stamp;
        // std::cout << "last_time" << std::showpoint << last_time << std::endl;
        cv::cvtColor(img_ptr->image, pre_image, cv::COLOR_RGB2GRAY);
        velocity.x = dlio_velocity.x();
        last_velocity.x = dlio_velocity.x();
        std::cout << dlio_velocity.x() << std::endl;
        std::cout << " " << P0[0] << " " << P0[2] << std::endl;
        std::cout << Q0[0] << " " << Q0[1] << " " << Q0[2] << Q0[3] << " " << R0[0] << " " << R0[1] << " " << R0[2] << " " << R0[3] << std::endl;
        kf_x.initialize(0, dlio_velocity.x(), P0[0], P0[2]);
        kf_x.setQR(Q0[0], Q0[1], Q0[2], Q0[3], R0[0], R0[1], R0[2], R0[3]);
    }
}


// void dlio_pose_callback(const geometry_msgs::PoseStamped::ConstPtr msg){
//     geometry_msgs::PoseStamped pose;
//     pose.header = msg->header;
//     pose.pose = msg->pose;
//     pose.pose.position.x = global_x;
//     dlio_pose_pub.publish(pose);
//     std_msgs::Float32 v_pose;
//     v_pose.data = msg->pose.position.x;
//     vision_pose_pub.publish(v_pose);
// }

void dlio_imu_callback(const sensor_msgs::Imu::ConstPtr msg){
    sensor_msgs::Imu imu_value = *msg;
    Eigen::Vector3f imu_linear;
    imu_linear.x() = imu_value.linear_acceleration.x * gravity;
    imu_linear.y() = imu_value.linear_acceleration.y * gravity;       
    imu_linear.z() = imu_value.linear_acceleration.z * gravity;

    Eigen::Vector3f body_gravity_vec = orientation_value * gravity_vec;
    imu_linear = imu_linear - body_gravity_vec;
    imu_value.linear_acceleration.x = imu_linear.x();
    imu_value.linear_acceleration.y = imu_linear.y();
    imu_value.linear_acceleration.z = imu_linear.z();
    imu_buffer.push_front(imu_value);
}

void dlio_odom_callback(const nav_msgs::Odometry::ConstPtr msg){
    Eigen::Vector3f world_velocity;
    world_velocity.x() = msg->twist.twist.linear.x;
    world_velocity.y() = msg->twist.twist.linear.y;
    world_velocity.z() = msg->twist.twist.linear.z;
    orientation_value.w() = msg->pose.pose.orientation.w;
    orientation_value.x() = msg->pose.pose.orientation.x;
    orientation_value.y() = msg->pose.pose.orientation.y;
    orientation_value.z() = msg->pose.pose.orientation.z;

    pitch = orientation_value.toRotationMatrix().eulerAngles(0,1,2)[1];
    dlio_velocity = orientation_value * world_velocity;
    dlio_pose_msg.x() = msg->pose.pose.position.x;
    dlio_pose_msg.y() = msg->pose.pose.position.y;    
    dlio_pose_msg.z() = msg->pose.pose.position.z;
    // std::cout << "pitch = " << pitch * 180 / M_PI << std::endl;
    if(abs(pitch) > 10) {
        ROS_ERROR("pitch = %f", pitch);
    }
}

void dlio_shift_callback(const std_msgs::Bool::ConstPtr msg) {
    opt_flow_off = msg->data;
}

int main(int argc,char **argv){
    ros::init(argc,argv,"optical_imu_fusion");
    ros::NodeHandle nh;

    std::cout << "------optical_imu_fusion start------" << std::endl;
    //load param
    ros::param::param<std::vector<float>>("~optical/kalman/P", P0, std::vector<float>{1,0,0,1});
    ros::param::param<std::vector<float>>("~optical/kalman/Q", Q0, std::vector<float>{1,0,0,1});
    ros::param::param<std::vector<float>>("~optical/kalman/R", R0, std::vector<float>{1,0,0,1});
    ros::param::param<float>("~optical/param/f_x", f_x, 2012.6687);
    ros::param::param<float>("~optical/param/f_y", f_y, 2012.6687);
    ros::param::param<float>("~optical/param/max_pixel_per_frame", max_pixel_per_frame, 18.72);
    ros::param::param<int>("~optical/windowSize/x",window_size_x, 3);
    ros::param::param<int>("~optical/windowSize/vel",window_size_vel, 10);

    


    // debug use
    // dlio_pose_pub = nh.advertise<geometry_msgs::Pose>("/optical/pose11",10);

    //dlio topic
    dlio_imu_sub = nh.subscribe("/livox/imu", 1000, dlio_imu_callback);
    dlio_odom_sub = nh.subscribe("/robot/dlio/odom_node/odom",100, dlio_odom_callback);
    dlio_shift_sub = nh.subscribe("/loff/Lidar_good",100, dlio_shift_callback);

    //pose pub
    optical_pose_pub = nh.advertise<geometry_msgs::Vector3>("/optical_code_pose",100);

    //distance sub
    distance_sub=nh.subscribe("/lidar/distance",100,lidar_callback);

    //image sub
    image_sub = nh.subscribe("/usb_cam_800/image_raw", 1, image_callback);

    //filter_buffer分配空间
    filter_buffer_x.reserve(window_size_x);
    filter_buffer_vel.reserve(window_size_vel);
    // filter_buffer.reserve(kFilterWindowSize);

    ros::spin();
    return 0;
}