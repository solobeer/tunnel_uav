#include <ros/ros.h>
#include <ros/package.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h> 
#include <std_msgs/Int32.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int16_t comb16(uint8_t low ,uint8_t high);
void write_callback(const std_msgs::Int32::ConstPtr& msg);
std::string log_path_create();
void log_title(std::string log_path);

