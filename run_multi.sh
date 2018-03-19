#!/bin/bash

USAGE="Example usage: source run_multi.sh ~/git/capstone/ros"
SD5_LAUNCH=0
SD5_PATH="$1/src/sd5"
SD5_EXEC="$1/devel/lib/sd5/sd5_node"
SD5_SETUP="$1/devel/setup.bash"


if [ ! -d "build" ]; then
    echo "No build directory found. Run 'make posix_sitl_default gazebo' \
then quit gazebo and execute run_multi.sh again."
    exit 1
fi

if [ ! $1 ]; then
    echo "No path argument supplied. Running just multi in simulator."

    source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/posix_sitl_default
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
    export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo

    roslaunch px4 multi_uav_mavros_sitl.launch

    exit 0
fi

if [ ! -d $1 ]; then
    echo "Path supplied is not a directory"
    echo $USAGE
    exit 1
fi


if [ ! -d $SD5_PATH ]; then
    echo "Path supplied is not ROS workspace where src/sd5 lives"
    echo $USAGE
    exit 1
fi

if [ ! -f $SD5_EXEC ]; then
    echo "Can't find sd5 node. Make sure to build sd5 node with catkin_make"
    exit 1
fi

source $SD5_SETUP
source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/posix_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
echo "ROS_PACKAGE_PATH: $ROS_PACKAGE_PATH"

roslaunch px4 sd5_multi.launch
