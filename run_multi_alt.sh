#!/bin/bash

source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/posix_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
echo "ROS_PACKAGE_PATH: $ROS_PACKAGE_PATH"

roslaunch px4 multi_uav_mavros_sitl.launch
