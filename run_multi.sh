#!/bin/bash

if ! echo $ROS_PACKAGE_PATH | grep -q 'sitl_gazebo'; then
    source multi_files/setup_ros_path
fi

roslaunch px4 multi_uav_mavros_sitl.launch
