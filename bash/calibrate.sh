# sleep 2s
{
gnome-terminal -t "camera" -- bash -c "source ~/usb_cam/devel/setup.bash;
                                    roslaunch usb_cam usb_cam_800.launch"
}&

{
gnome-terminal -t "camera_calibrate" -- bash -c "rosrun camera_calibration cameracalibrator.py --size 11x8 --square 0.03 image:=/usb_cam_800/image_raw"
}&