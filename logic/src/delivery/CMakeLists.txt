cmake_minimum_required(VERSION 3.0.2)
project(delivery)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  agents_lib
  tf2
  tf2_ros
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  NewGoal.msg
#   Message1.msg
#   Message2.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
#   Service1.srv
#   Service2.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES delivery
CATKIN_DEPENDS roscpp rospy  geometry_msgs std_msgs message_runtime agents_lib tf2 tf2_ros
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(delivery src/main.cpp)
target_link_libraries(delivery ${catkin_LIBRARIES})

