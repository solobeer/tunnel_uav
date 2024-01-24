source ~/corridor_ws/devel/setup.bash
gnome-terminal -- bash -c "roslaunch opt_imu_fusion start.launch"

sleep 0.5s
gnome-terminal -- bash -c "roslaunch lidar_opticalflow_fusion loff.launch"

####  设置成仿真时间
sleep 3s
gnome-terminal -- bash -c "rosparam set use_sim_time true"

###  播放bag
#gnome-terminal -- bash -c "rosbag play ~/Dataset/实验室内部环境/2023-10-28-18-15-45.bag  --clock;"
#gnome-terminal -- bash -c "rosbag play ~/Dataset/校外二楼/2023-07-28-14-58-55.bag  --clock;"
gnome-terminal -- bash -c "rosbag play ~/Dataset/10.31_科技园二楼/2023-10-31-15-56-33.bag -r 1  --clock;"
