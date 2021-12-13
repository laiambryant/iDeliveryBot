# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "delivery: 3 messages, 2 services")

set(MSG_I_FLAGS "-Idelivery:/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(delivery_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_custom_target(_delivery_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "delivery" "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" ""
)

get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_custom_target(_delivery_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "delivery" "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" ""
)

get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_custom_target(_delivery_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "delivery" "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" ""
)

get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_custom_target(_delivery_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "delivery" "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" ""
)

get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_custom_target(_delivery_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "delivery" "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
)
_generate_msg_cpp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
)
_generate_msg_cpp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
)

### Generating Services
_generate_srv_cpp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
)
_generate_srv_cpp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
)

### Generating Module File
_generate_module_cpp(delivery
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(delivery_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(delivery_generate_messages delivery_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_dependencies(delivery_generate_messages_cpp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_dependencies(delivery_generate_messages_cpp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_dependencies(delivery_generate_messages_cpp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_dependencies(delivery_generate_messages_cpp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_dependencies(delivery_generate_messages_cpp _delivery_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(delivery_gencpp)
add_dependencies(delivery_gencpp delivery_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS delivery_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
)
_generate_msg_eus(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
)
_generate_msg_eus(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
)

### Generating Services
_generate_srv_eus(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
)
_generate_srv_eus(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
)

### Generating Module File
_generate_module_eus(delivery
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(delivery_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(delivery_generate_messages delivery_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_dependencies(delivery_generate_messages_eus _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_dependencies(delivery_generate_messages_eus _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_dependencies(delivery_generate_messages_eus _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_dependencies(delivery_generate_messages_eus _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_dependencies(delivery_generate_messages_eus _delivery_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(delivery_geneus)
add_dependencies(delivery_geneus delivery_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS delivery_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
)
_generate_msg_lisp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
)
_generate_msg_lisp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
)

### Generating Services
_generate_srv_lisp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
)
_generate_srv_lisp(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
)

### Generating Module File
_generate_module_lisp(delivery
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(delivery_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(delivery_generate_messages delivery_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_dependencies(delivery_generate_messages_lisp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_dependencies(delivery_generate_messages_lisp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_dependencies(delivery_generate_messages_lisp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_dependencies(delivery_generate_messages_lisp _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_dependencies(delivery_generate_messages_lisp _delivery_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(delivery_genlisp)
add_dependencies(delivery_genlisp delivery_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS delivery_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
)
_generate_msg_nodejs(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
)
_generate_msg_nodejs(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
)

### Generating Services
_generate_srv_nodejs(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
)
_generate_srv_nodejs(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
)

### Generating Module File
_generate_module_nodejs(delivery
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(delivery_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(delivery_generate_messages delivery_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_dependencies(delivery_generate_messages_nodejs _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_dependencies(delivery_generate_messages_nodejs _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_dependencies(delivery_generate_messages_nodejs _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_dependencies(delivery_generate_messages_nodejs _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_dependencies(delivery_generate_messages_nodejs _delivery_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(delivery_gennodejs)
add_dependencies(delivery_gennodejs delivery_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS delivery_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
)
_generate_msg_py(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
)
_generate_msg_py(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
)

### Generating Services
_generate_srv_py(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
)
_generate_srv_py(delivery
  "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
)

### Generating Module File
_generate_module_py(delivery
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(delivery_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(delivery_generate_messages delivery_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Cmd.msg" NAME_WE)
add_dependencies(delivery_generate_messages_py _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Pose.msg" NAME_WE)
add_dependencies(delivery_generate_messages_py _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/msg/Status.msg" NAME_WE)
add_dependencies(delivery_generate_messages_py _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Call.srv" NAME_WE)
add_dependencies(delivery_generate_messages_py _delivery_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/liam/Desktop/iDeliveryBot_srv/iDelivery_bot_logic/src/delivery/srv/Map.srv" NAME_WE)
add_dependencies(delivery_generate_messages_py _delivery_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(delivery_genpy)
add_dependencies(delivery_genpy delivery_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS delivery_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/delivery
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(delivery_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/delivery
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(delivery_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/delivery
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(delivery_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/delivery
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(delivery_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/delivery
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(delivery_generate_messages_py std_msgs_generate_messages_py)
endif()
