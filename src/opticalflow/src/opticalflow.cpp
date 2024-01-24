#include "opticalflow.h"
#include "ros/ros.h"
#include "serial/serial.h"
#include <iostream>
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include <opticalflow/optical.h>


int main (int argc, char** argv) 
{ 
    // 初始化节点 
    ros::init(argc, argv, "opticalflow"); 
    // 声明节点句柄 
    ros::NodeHandle nh; 
    ros::Publisher rec_msg_pub = nh.advertise<opticalflow::optical>("/usb_opticalflow",1);
    serial::Serial ser; //声明串口对象 
    try 
    { 
        // 设置串口属性，并打开串口 
        ser.setPort("/dev/tty_hub_left1"); // /dev/ttyFlow   ttyUSB4
        ser.setBaudrate(500000);  //
        ser.setBytesize(serial::bytesize_t::eightbits);
        ser.setStopbits(serial::stopbits_t::stopbits_one);
        ser.setFlowcontrol(serial::flowcontrol_t::flowcontrol_none);
        serial::Timeout time_out = serial::Timeout::simpleTimeout(1000); 
        ser.setTimeout(time_out); 
        ser.open(); 
    } 
    catch (serial::IOException& e) 
    { 
        ROS_ERROR_STREAM("Unable to open OpticalFlow port\n"); 
        return -1;  
    } 

    //检测串口是否已经打开，并给出提示信息 
    if(ser.isOpen()) 
    { 
        ROS_INFO_STREAM("Serial OpticalFlow Port initialized\n"); 
    } 
    else 
    { 
        ROS_ERROR_STREAM("Serial is not open successfully\n");
        return -1; 
    } 

    // 指定循环的频率 
    ros::Rate rate(30);    // 光流发布频率为50hz
    

    uint8_t count = 0;
    int idx = -1;   // 帧头位置
    uint8_t buff_optical[2000];
    uint8_t data_len; 
    opticalflow::optical rec_msg;
    while(ros::ok()) 
    { 
        uint8_t sum = 0, add = 0;
        rec_msg.header.seq = count++;
        rec_msg.header.stamp = ros::Time::now();
        rec_msg.header.frame_id = "rec_msg";
        size_t bufferLen = ser.available();
    
        if(bufferLen)
        { 
            printf("bufferlen:%d\n", bufferLen);
            bufferLen = ser.read(buff_optical, bufferLen); //读取的总长度
            for(int i = 0;i < bufferLen; i++) {
                if(buff_optical[i] == 0xaa && buff_optical[i+1] == 0xff) {  // 找到帧头位置
                    idx = i;
                    break;
                }
            }
            if(idx == -1){
                rate.sleep();
                continue;
            }

            data_len = buff_optical[idx+3];//数据部分的长度
            //功能码 0x51 匿名光流数据
            if(buff_optical[idx+2] == 0x51) {
                // 惯导融合后光流数据 cm/s
                if(buff_optical[idx+4] == 0x02) {
                    float dx2 = comb16(buff_optical[idx+6], buff_optical[idx+7])/100.00;
                    float dy2 = comb16(buff_optical[idx+8], buff_optical[idx+9])/100.00;
                    float dxfix = comb16(buff_optical[idx+10], buff_optical[idx+11])/100.00;
                    float dyfix = comb16(buff_optical[idx+12], buff_optical[idx+13])/100.00;
                    float integx = comb16(buff_optical[idx+14], buff_optical[idx+15])/100.00;
                    float integy = comb16(buff_optical[idx+16], buff_optical[idx+17])/100.00;
                    uint8_t quality = uint8_t(buff_optical[idx+18]) ;
                    rec_msg.mode = 2;
                    rec_msg.vel_rate.x = dx2;
                    rec_msg.vel_rate.y = dy2;
                    rec_msg.vel_rate_fix.x = dxfix;
                    rec_msg.vel_rate_fix.y = dyfix;
                    rec_msg.vel_rate_integ.x = integx;
                    rec_msg.vel_rate_integ.y = integy;
                    rec_msg.quality = quality / 255.0;
                } //融合后的光流数据  cm/s
                // else if(buff_optical[idx+4] == 0x01){ 
                //     float dx1 = comb16(buff_optical[idx+6], buff_optical[idx+7])/100.00;
                //     float dy1 = comb16(buff_optical[idx+8], buff_optical[idx+9])/100.00;
                //     rec_msg.mode = 1;
                //     rec_msg.vel_rate.x = dx1;
                //     rec_msg.vel_rate.y = dy1;
                // }//原始光流数据  pix/20ms  像素/20毫秒
                // else if(buff_optical[idx+4] == 0x00){
                //     float dx0 = buff_optical[idx+6];
                //     float dy0 = buff_optical[idx+7];
                //     rec_msg.mode = 0;
                //     rec_msg.vel_rate.x = dx0;
                //     rec_msg.vel_rate.y = dy0;
                // }
                if( rec_msg.quality < 0.1)    //  自定义阈值判断数据质量是否太差
                {
                       cout << "Data quality is too bad!!!" << endl;
                       continue;
                }
                for(uint8_t i = 0; i < data_len + 4; i++){
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+data_len + 4] && add == buff_optical[idx+data_len + 5]){
                    cout << "0x51 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x51 sumcheck fail " << endl;
                    cout << "rec_msg.quality:" << rec_msg.quality << endl;
                    continue;
                }
                rec_msg.frameClass = 51;
                std::cout   
                    << "  " << rec_msg.frameClass<< "  "  << rec_msg.mode 
                    << "  " << rec_msg.vel_rate.x << "  " << rec_msg.vel_rate.y 
                    << "  " << rec_msg.vel_rate_fix.x << "  " << rec_msg.vel_rate_fix.y 
                    << "  " << rec_msg.vel_rate_integ.x << "  " << rec_msg.vel_rate_integ.y 
                    << "  " << rec_msg.quality 
                    << std::endl;
                rec_msg_pub.publish(rec_msg);
            }
            //测距信息
            else if(buff_optical[idx+2] == 0x34) {
                uint8_t dir = buff_optical[idx+4]; //0:下 恒为0
                uint16_t angle = comb16(buff_optical[idx+5], buff_optical[idx+6]); //恒为0
                int32_t dis = buff_optical[idx+7] | buff_optical[idx+8] << 8 | buff_optical[idx+9] << 16 | buff_optical[idx+10] << 24;
                rec_msg.dir = dir;
                rec_msg.angle = angle;
                rec_msg.dis = dis / 100.00;
                //cout << "dis:  "<< rec_msg.dis  << endl;
                if(dis == 0xFFFFFFFF)
                    cout << "Invalid data!!!" << endl;
                for(uint8_t i = 0; i < data_len + 4; i++)
                {
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+data_len + 4] && add == buff_optical[idx+data_len + 5]){
                    cout << "0x34 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x34 sumcheck fail " << endl;
                    continue;
                }
                rec_msg.frameClass = 34;
                   std::cout   <<  rec_msg.dis << std::endl;
                // rec_msg_pub.publish(rec_msg);
            }
        }
        // ofstream of_stream;
        // of_stream.open(log_path, std::ios::app | std::ios::out);
        // of_stream << "  " << rec_msg.frameClass<< "  "  << rec_msg.mode 
        //             << "  " << rec_msg.vel_rate.x << "  " << rec_msg.vel_rate.y 
        //             << "  " << rec_msg.vel_rate_fix.x << "  " << rec_msg.vel_rate_fix.y 
        //             << "  " << rec_msg.vel_rate_integ.x << "  " << rec_msg.vel_rate_integ.y 
        //             << "  " << rec_msg.quality << "  " << rec_msg.dis<<" "<<lidarf_data
        //             << std::endl;
        // of_stream.close();
        // read_pub.publish(rec_msg); 
        idx = -1;
        //处理ROS的信息，比如订阅消息,并调用回调函数 
        rate.sleep();
    }
}

/***************************************************记录数据文件名生成***************************************************/
std::string log_path_create() {
  char log_name[100] = {0};
  time_t time_curr = time(NULL);   
  tm* time_needle = localtime(&time_curr);
  sprintf(log_name, "/flightlog/%02d%02d%02d%02d.csv", time_needle->tm_mon+1,time_needle->tm_mday,time_needle->tm_hour,time_needle->tm_min);
  std::string return_value = ros::package::getPath("opticalflow") + log_name;
  return return_value;
}


/***************************************************记录的数据***************************************************/
// void log_title(std::string log_path) {
//     of_stream.open(log_path, std::ios::app|std::ios::out);
//     of_stream
//                 << " frameClass " << " mode " << " dx2 " << " dy2 " << " dxfix " << " dyfix " 
//                 << " integx " << " integy " <<" quality "<<" dis " << " lidarf_data "
//                 << std::endl;
//     of_stream.close();
// }


int16_t comb16(uint8_t low ,uint8_t high){
    int16_t temp=0;
    temp = ((int16_t)high << 8);
    temp |= ((int16_t)low);
    return temp;
}