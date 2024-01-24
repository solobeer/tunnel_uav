source ~/corridor_ws/devel/setup.bash

gnome-terminal -- bash -c "roslaunch opt_imu_fusion start.launch"

####  设置成仿真时间
sleep 13s
gnome-terminal -- bash -c "rosparam set use_sim_time true"

###  播放bag
gnome-terminal -- bash -c "rosbag play ~/Dataset/实验室内部环境/2023-10-28-18-15-45.bag  --clock;"
