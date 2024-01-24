#include<ros/ros.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>

cv::VideoWriter videoWriter;
std::string videoPath;
std::string image_topic_name;
bool firstImage = true;

void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    cv::Mat img = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::RGB8)->image;
    if (firstImage == true) {
        firstImage = false;
        videoWriter.open(videoPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, img.size());
        if (videoWriter.isOpened() == false) {
            std::cerr << "Error: Could not open video file for writing." << std::endl;
        }
        return;
    }
    videoWriter.write(img);
    return;
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "recordmp4");
    ros::NodeHandle nh;
    ros::param::param<std::string>("~recordmp4/save_path", videoPath, "/home/hzb/test.mp4");
    ros::param::param<std::string>("~recordmp4/image_topic", image_topic_name, "/usb_cam_800/image_raw");
    ros::Subscriber img_sub = nh.subscribe(image_topic_name, 1, imageCallback);
    ros::spin();
    videoWriter.release();
    return 0;
}