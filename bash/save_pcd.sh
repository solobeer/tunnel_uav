# 
{
gnome-terminal -t "mavros" -- bash -c "source ~/lidar_ws_build/devel/setup.bash; 
                                        rosservice call /robot/dlio_map/save_pcd 0.01 ~/map;exec bash"
}&