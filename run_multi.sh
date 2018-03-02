#!/bin/bash

if ! echo $ROS_PACKAGE_PATH | grep -q 'sitl_gazebo'; then
    source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/posix_sitl_default
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
fi

source ~/dev/repos/capstone/ros/devl/setup.bash
roslaunch px4 multi_uav_mavros_sitl.launch
