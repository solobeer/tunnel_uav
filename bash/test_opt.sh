
# 启动livox驱动
sleep 2s
{
gnome-terminal -t "livox_driver" -- bash -c "source ~/livox/devel/setup.bash; 
                                            roslaunch livox_ros_driver2 msg_MID360.launch"
}&


# 启动DLIO
sleep 5s
{
gnome-terminal -t "dlio_lidar_slam" -- bash -c "source ~/lidar_ws_build/devel/setup.bash;
                                            roslaunch direct_lidar_inertial_odometry dlio.launch"
}&



# 启动匿名光流
sleep 1s
{
gnome-terminal -t "loff" -- bash -c "source ~/corridor_ws/devel/setup.bash;
                                        
                                    roslaunch opticalflow opticalflow.launch"
}&


# 启动bag记录
# {
# gnome-terminal -t "rostopic_echo" -- bash -c "rosbag record -a;exec bash"
# }&

