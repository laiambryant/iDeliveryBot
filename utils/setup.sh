#!/bin/bash
ROS_DISTRO="melodic"
CURRENT_DIR=${PWD}
PACKAGES="libeigen3-dev \
 libsuitesparse-dev \
 ninja-build \
 libncurses5-dev \
 libwebsockets-dev \
 libreadline-dev \
 qtdeclarative5-dev \
 qt5-qmake \
 libqglviewer-dev-qt5 \
 libudev-dev \
 freeglut3-dev \
 libgtest-dev \
 arduino \
 arduino-mk \
 libglfw3-dev \
 python-catkin-tools \
 python-rosdep \
 python-rosinstall \
 python-rosinstall-generator \
 python-wstool build-essential \
 libbullet-dev \
 ros-${ROS_DISTRO}-grid-map-msgs"

if [ -z "$1" ]; then
    echo "please specify a Ros distro [ melodic or noetic]"
    echo "usage: setup.sh {melodic|noetic}"
    exit 0
fi

ROS_DISTRO="$1"
ROS_SETUP="/opt/ros/${ROS_DISTRO}/setup.bash"
if [ ! -f "${ROS_SETUP}" ]; then
    echo "ros distro ${ROS_DISTRO} not found, install ROS first";
    exit 0;
fi
source ${ROS_SETUP}

sudo rosdep init
rosdep update
sudo apt remove ros-${ROS_DISTRO}-navigation # we override this
sudo apt install ${PACKAGES}
WS_DIR=${PWD}/workspaces/srrg2_labiagi/
cd ${WS_DIR}/src
catkin_init_workspace
cd ${WS_DIR}
catkin config --blacklist srrg2_solver_calib_addons srrg2_solver_extras srrg2_solver_experiments srrg2_solver_star
catkin build
cd ${CURRENT_DIR}

