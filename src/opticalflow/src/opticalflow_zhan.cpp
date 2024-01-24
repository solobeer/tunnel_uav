#include "opticalflow.h"
#include "ros/ros.h"
#include "serial/serial.h"
#include <iostream>
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include <opticalflow/optical.h>

serial::Serial ser; //声明串口对象 
int idx = -1;
std::string log_path;
std::ofstream of_stream;
opticalflow::optical rec_msg;
float lidarf_data = 0.0;
// double curtime=0.0;

int main (int argc, char** argv) 
{ 
    // 记录数据
    log_path = log_path_create();
    log_title(log_path);

    //初始化节点 
    ros::init(argc, argv, "opticalflow"); 
    //声明节点句柄 
    ros::NodeHandle nh; 
    //订阅主题，并配置回调函数 
    //定义串口对象


    try 
    { 
        //设置串口属性，并打开串口 
        ser.setPort("/dev/ttyUSB0"); // /dev/ttyFlow   ttyUSB4
        ser.setBaudrate(115200);  //
        ser.setBytesize(serial::bytesize_t::eightbits);
        ser.setStopbits(serial::stopbits_t::stopbits_one);
        ser.setFlowcontrol(serial::flowcontrol_t::flowcontrol_none);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000); 
        ser.setTimeout(to); 
        ser.open(); 
    } 
    catch (serial::IOException& e) 
    { 
        ROS_INFO_STREAM("Unable to open OpticalFlow port "); 
        return -1;  
    } 
    //检测串口是否已经打开，并给出提示信息 
    if(ser.isOpen()) 
    { 
        ROS_INFO_STREAM("Serial OpticalFlow Port initialized"); 
    } 
    else 
    { 
        return -1; 
    } 

    //指定循环的频率 
    ros::Rate loop_rate(30);
    

    int count = 0;
    while(ros::ok()) 
    { 

        uint8_t buff_optical[1000], sum = 0, add = 0, len;
        rec_msg.header.seq = count++;
        rec_msg.header.stamp = ros::Time::now();
        rec_msg.header.frame_id = "rec_msg";
        size_t bufferLen = ser.available();
    
        if(bufferLen)
        { 
            bufferLen = ser.read(buff_optical, bufferLen);//读取的总长度
            //  for(int i=0;i<bufferLen;i++){
            //     //printf("%u ",buff_optical[i]);
            //     std::cout<< std::hex << (buff_optical[i]&0xff) << "  ";
            // }
            for(int i=0;i<bufferLen;i++){
                if(buff_optical[i]== 0xaa && buff_optical[i+1]== 0xff){
                    idx = i;
                    //cout<<" find frame front"<<endl;
                    break;
                }
            }
            if(idx == -1){
                continue;
            }
            cout<<endl;
            //cout<<"bufferLen "<<bufferLen<<endl;
            len = buff_optical[idx+3];//数据部分的长度
            //功能码 0x51 匿名光流数据
            if(buff_optical[idx+2] == 0x51){
                //cout<<51<<endl;
                uint8_t valid = buff_optical[idx+5];
               
                //模式码 惯导融合后光流数据  cm/s
                if(buff_optical[idx+4] == 0x02){
                    // double delttime = ros::Time::now().toSec() - curtime;
                    // curtime =ros::Time::now().toSec();
                    // cout<<"delttime:  "<< delttime<<endl;
                    float dx2 = comb16(buff_optical[idx+6], buff_optical[idx+7])/100.00;
                    float dy2 = comb16(buff_optical[idx+8], buff_optical[idx+9])/100.00;
                    float dxfix = comb16(buff_optical[idx+10], buff_optical[idx+11])/100.00;
                    float dyfix = comb16(buff_optical[idx+12], buff_optical[idx+13])/100.00;
                    float integx = comb16(buff_optical[idx+14], buff_optical[idx+15])/100.00;
                    float integy = comb16(buff_optical[idx+16], buff_optical[idx+17])/100.00;
                    float quality = int16_t(buff_optical[idx+18]) ;
                    rec_msg.mode = 2;
                    rec_msg.vel_rate.x = dx2;
                    rec_msg.vel_rate.y = dy2;
                    rec_msg.vel_rate_fix.x = dxfix;
                    rec_msg.vel_rate_fix.y = dyfix;
                    rec_msg.vel_rate_integ.x = integx;
                    rec_msg.vel_rate_integ.y = integy;
                    rec_msg.quality = quality;
                    //cout << "quality:  "<< rec_msg.quality  << endl;

                } //融合后的光流数据  cm/s
                else if(buff_optical[idx+4] == 0x01){ 
                    float dx1 = comb16(buff_optical[idx+6], buff_optical[idx+7])/100.00;
                    float dy1 = comb16(buff_optical[idx+8], buff_optical[idx+9])/100.00;
                    rec_msg.mode = 1;
                    rec_msg.vel_rate.x = dx1;
                    rec_msg.vel_rate.y = dy1;
                }//原始光流数据  pix/20ms  像素/20毫秒
                else if(buff_optical[idx+4] == 0x00){
                    float dx0 = buff_optical[idx+6];
                    float dy0 = buff_optical[idx+7];
                    rec_msg.mode = 0;
                    rec_msg.vel_rate.x = dx0;
                    rec_msg.vel_rate.y = dy0;
                }
                if( rec_msg.quality < 55)    //  自定义阈值判断数据质量是否太差
                {
                       cout << "Data quality is too bad!!!" << endl;
                       continue;
                }
                for(uint8_t i = 0; i < len + 4; i++){
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+len + 4] && add == buff_optical[idx+len + 5]){
                    cout << "0x51 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x51 sumcheck fail " << endl;
                    continue;
                }

                rec_msg.frameClass = 51;
            }
            //测距信息
            else if(buff_optical[idx+2] == 0x34){
                uint8_t dir = buff_optical[idx+4]; //0:下 恒为0
                uint16_t angle = comb16(buff_optical[idx+5], buff_optical[idx+6]); //恒为0
                int32_t dis = buff_optical[idx+7] | buff_optical[idx+8] << 8 | buff_optical[idx+9] << 16 | buff_optical[idx+10] << 24;
                rec_msg.dir = dir;
                rec_msg.angle = angle;
                rec_msg.dis = dis/100.00;
                //cout << "dis:  "<< rec_msg.dis  << endl;
                if(dis == 0xFFFFFFFF)
                    cout << "Invalid data!!!" << endl;
                for(uint8_t i = 0; i < len + 4; i++)
                {
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+len + 4] && add == buff_optical[idx+len + 5]){
                    cout << "0x34 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x34 sumcheck fail " << endl;
                    continue;
                }

                rec_msg.frameClass = 34;
            }
            //惯性信息数据
            else if(buff_optical[idx+2] == 0x01){
                int16_t accx = comb16(buff_optical[idx+4], buff_optical[idx+5]);
                int16_t accy = comb16(buff_optical[idx+6], buff_optical[idx+7]);
                int16_t accz = comb16(buff_optical[idx+8], buff_optical[idx+9]);
                int16_t gryx = comb16(buff_optical[idx+10], buff_optical[idx+11]);
                int16_t gryy = comb16(buff_optical[idx+12], buff_optical[idx+13]);
                int16_t gryz = comb16(buff_optical[idx+14], buff_optical[idx+15]);
                rec_msg.acc_rate.x = accx;
                rec_msg.acc_rate.y = accy;
                rec_msg.acc_rate.z = accz;
                rec_msg.gry_rate.x = gryx;
                rec_msg.gry_rate.y = gryy;
                rec_msg.gry_rate.z = gryz;
                for(uint8_t i = 0; i < len + 4; i++)
                {
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+len + 4] && add == buff_optical[idx+len + 5]){
                    cout << "0x01 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x01 sumcheck fail " << endl;
                    continue;
                }

                rec_msg.frameClass = 1;
            }
            //姿态数据
            else if(buff_optical[idx+2] == 0x04){
                int16_t v0 = comb16(buff_optical[idx+4], buff_optical[idx+5]);  //  比真实值放大了10000倍
                int16_t v1 = comb16(buff_optical[idx+6], buff_optical[idx+7]);
                int16_t v2 = comb16(buff_optical[idx+8], buff_optical[idx+9]);
                int16_t v3 = comb16(buff_optical[idx+10], buff_optical[idx+11]);
                rec_msg.quat.x = v0;
                rec_msg.quat.y = v1;
                rec_msg.quat.z = v2;
                rec_msg.quat.w = v3;
                for(uint8_t i = 0; i < len + 4; i++)
                {
                    sum += buff_optical[idx+i];
                    add += sum;
                }
                if(sum == buff_optical[idx+len + 4] && add == buff_optical[idx+len + 5]){
                    cout << "0x04 sumcheck sucess " << endl;
                }
                else{
                    cout << "0x04 sumcheck fail " << endl;
                    continue;
                }

                rec_msg.frameClass = 4;
            }
        }
        std::cout   
                << "  " << rec_msg.frameClass<< "  "  << rec_msg.mode 
                << "  " << rec_msg.vel_rate.x << "  " << rec_msg.vel_rate.y 
                << "  " << rec_msg.vel_rate_fix.x << "  " << rec_msg.vel_rate_fix.y 
                << "  " << rec_msg.vel_rate_integ.x << "  " << rec_msg.vel_rate_integ.y 
                << "  " << rec_msg.quality << "  " << rec_msg.dis
                << std::endl;
        ofstream of_stream;
        of_stream.open(log_path, std::ios::app | std::ios::out);
        of_stream << "  " << rec_msg.frameClass<< "  "  << rec_msg.mode 
                    << "  " << rec_msg.vel_rate.x << "  " << rec_msg.vel_rate.y 
                    << "  " << rec_msg.vel_rate_fix.x << "  " << rec_msg.vel_rate_fix.y 
                    << "  " << rec_msg.vel_rate_integ.x << "  " << rec_msg.vel_rate_integ.y 
                    << "  " << rec_msg.quality << "  " << rec_msg.dis<<" "<<lidarf_data
                    << std::endl;
        of_stream.close();
        // read_pub.publish(rec_msg); 
        idx = -1;
        //处理ROS的信息，比如订阅消息,并调用回调函数 
        ros::spinOnce(); 
        loop_rate.sleep(); 
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
void log_title(std::string log_path) {
    of_stream.open(log_path, std::ios::app|std::ios::out);
    of_stream
                << " frameClass " << " mode " << " dx2 " << " dy2 " << " dxfix " << " dyfix " 
                << " integx " << " integy " <<" quality "<<" dis " << " lidarf_data "
                << std::endl;
    of_stream.close();
}

void write_callback(const std_msgs::Int32::ConstPtr& msg)
{

}

int16_t comb16(uint8_t low ,uint8_t high){
    int16_t temp=0;
    temp = ((int16_t)high<<8);
    temp |=((int16_t)low);
    return temp;
}