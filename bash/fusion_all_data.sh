# 启动飞控链接
{
gnome-terminal -t "mavros" -- bash -c " roslaunch mavros px4.launch;exec bash"
}&

# 启动livox驱动
sleep 3s
{
gnome-terminal -t "livox_driver" -- bash -c "source ~/livox_driver_ws/devel/setup.bash; 
                                            roslaunch livox_ros_driver2 msg_MID360.launch"
}&



# #启动t265
sleep 1s
{
gnome-terminal -t "t265" -- bash -c "source ~/workspace/realsense/devel/setup.bash;
                                    roslaunch realsense2_camera rs_t265.launch"
}&

#启动下是相机
sleep 1s
{
gnome-terminal -t "camera" -- bash -c "source ~/usb_cam/devel/setup.bash;
                                    roslaunch usb_cam usb_cam.launch"
}&


# 启动DLIO
sleep 5s
{
gnome-terminal -t "dlio_lidar_slam" -- bash -c "source ~/3gorges_lidar_ws_build/devel/setup.bash;
                                            roslaunch direct_lidar_inertial_odometry dlio_origin.launch"
}&


# 启动雷达右侧深度距离发布节点 
# sleep 1s
# {
# gnome-terminal -t "vison_y_pub" -- bash -c "source ~/corridor_ws/devel/setup.bash;
#                                             rosrun path_plan vision_y"
# }&

# 启动路径规划
sleep 3s
{
gnome-terminal -t "path_plan" -- bash -c "source ~/corridor_ws/devel/setup.bash;
                                    roslaunch path_plan plan.launch"
}&

# 启动光流
# sleep 1s
# {
# gnome-terminal -t "loff" -- bash -c "source ~/corridor_ws/devel/setup.bash;
                                        
#                                     roslaunch lidar_opticalflow_fusion loff.launch"
# }&

#启动usb相机
# sleep 2s
# {
# gnome-terminal -t "camera" -- bash -c "source ~/usb_cam/devel/setup.bash;
#                                     roslaunch usb_cam usb_cam_800.launch"
# }&

#录制相机视频
# sleep 2s
# {
# gnome-terminal -t "record_mp4" -- bash -c "source ~/corridor_ws/devel/setup.bash;
#                                     roslaunch opt_imu_fusion recordmp4.launch"
# }&


# 启动匿名光流
sleep 1s
{
gnome-terminal -t "loff" -- bash -c "source ~/corridor_ws/devel/setup.bash;
                                        
                                    roslaunch opticalflow opticalflow.launch"
}&


# sleep 2s
# {
# gnome-terminal -t "camera" -- bash -c "source ~/usb_cam/devel/setup.bash;
#                                     roslaunch usb_cam usb_cam_800.launch"
# }&

# 启动位置发布loff
sleep 1s
{
gnome-terminal -t "loff" -- bash -c "source ~/corridor_ws/devel/setup.bash;
                                    roslaunch lidar_opticalflow_fusion loff.launch"
}&
# 启动bag记录
{
gnome-terminal -t "rostopic_echo" -- bash -c "rosbag record -a;exec bash"
}&

