# Install script for directory: /home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery/msg" TYPE FILE FILES
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery/srv" TYPE FILE FILES
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery/cmake" TYPE FILE FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/build/delivery/catkin_generated/installspace/delivery-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/include/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/share/roseus/ros/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/share/common-lisp/ros/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/share/gennodejs/ros/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/lib/python3/dist-packages/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/devel/lib/python3/dist-packages/delivery")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/build/delivery/catkin_generated/installspace/delivery.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery/cmake" TYPE FILE FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/build/delivery/catkin_generated/installspace/delivery-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery/cmake" TYPE FILE FILES
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/build/delivery/catkin_generated/installspace/deliveryConfig.cmake"
    "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/build/delivery/catkin_generated/installspace/deliveryConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/delivery" TYPE FILE FILES "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/package.xml")
endif()

