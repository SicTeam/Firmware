#!/bin/bash

if ! echo $ROS_PACKAGE_PATH | grep -q 'sitl_gazebo'; then
    source setup_multi_source
fi

roslaunch px4 multi_uav_mavros_sitl.launch
