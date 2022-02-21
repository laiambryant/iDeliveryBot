#include "srv_monitor_lib/srv_monitor.h"
#include "srv_monitor_lib/message_creator.h"

#include <ros/ros.h>
#include <unistd.h>
#include <sstream>

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include "std_msgs/String.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include "delivery/Res.h"

#define T 100

#ifndef RES_NUMS
    #define CALL_RES 1
    #define SEND_RES 2
    #define RCVD_RES 3
    #define CANCEL_RES 4
    #define TIMEOUT_RES 5
    #define ARRIVED_RES 6
#endif

using namespace ros;

//Global vars------------------------------------------------------------------------------------------------
tf2_ros::Buffer tf_buffer;
int loops_counter = 0;
int logged_in_users = 0;
int pos_msgs = 0;

//Create monitor and parser
req_parser parser;
srv_monitor mtr = srv_monitor(5100);

//Subscriber Callbacks---------------------------------------------------------------------------------------

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf);
void res_callback(const delivery::Res &res);

int main(int argc, char **argv){

    ros::init(argc,argv,"pos_update");
    ROS_INFO("Starting updater...");
    
    ros::NodeHandle n; 
    ros::Rate loop_rate(T);
    tf2_ros::TransformListener tfListener(tf_buffer);

//Publishers-------------------------------------------------------------------------------------------------


//Subscribers------------------------------------------------------------------------------------------------

    ros::Subscriber sub_tf = n.subscribe("tf", 1, send_robot_pos_callback);
    ros::Subscriber sub_res = n.subscribe("/Res", 1, res_callback);
 
//Timers-----------------------------------------------------------------------------------------------------

    while(ros::ok()){  

        ros::spinOnce();
        loop_rate.sleep();
        loops_counter++;
    
    }   
    
    return EXIT_SUCCESS;

}

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf){
    sleep(2);
    bool can_transf = tf_buffer.canTransform("map", "base_footprint", ros::Time(0));
    if(can_transf){

        geometry_msgs::TransformStamped tr_stamped;
        tr_stamped = tf_buffer.lookupTransform("map", "base_footprint", ros::Time(0));
/*
        ROS_INFO_STREAM("Position x:" << tr_stamped.transform.translation.x);
        ROS_INFO_STREAM("Position y:" << tr_stamped.transform.translation.y);
        ROS_INFO_STREAM("Orientation w:" << tr_stamped.transform.rotation.w);
*/
        double x_pos = tr_stamped.transform.translation.x;
        double y_pos = tr_stamped.transform.translation.y;
        double orientation = tr_stamped.transform.rotation.w;

        string msg; msg += "{\"x_pos\":\""; msg += std::to_string(x_pos); msg += "\",\"y_pos\":\""; msg += std::to_string(y_pos); msg += "\"}";

        mtr.send_msg(msg, robo_pos);

        ROS_INFO_STREAM(msg);

   }
}

void res_callback(const delivery::Res &res){
    string msg;
    switch (res.type){
    case CALL_RES:
        msg += "{\"x_sender\":\""; msg += std::to_string(res.x_sender); msg += "\",\"y_sender\":\""; 
        msg += std::to_string(res.y_sender); msg += "\",\"x_reciever\":\""; msg += std::to_string(res.x_reciever); 
        msg += "\",\"y_reciever\":\""; msg += std::to_string(res.y_reciever); msg += "\"}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, call);
        break;
    case SEND_RES: 
        msg += "{\"x_sender\":\""; msg += std::to_string(res.x_sender); msg += "\",\"y_sender\":\""; 
        msg += std::to_string(res.y_sender); msg += "\",\"x_reciever\":\""; msg += std::to_string(res.x_reciever); 
        msg += "\",\"y_reciever\":\""; msg += std::to_string(res.y_reciever); msg += "\"}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, obj_send);
        break;
    case RCVD_RES: 
        msg += "{\"x_sender\":\""; msg += std::to_string(res.x_sender); msg += "\",\"y_sender\":\""; 
        msg += std::to_string(res.y_sender); msg += "\",\"x_reciever\":\""; msg += std::to_string(res.x_reciever); 
        msg += "\",\"y_reciever\":\""; msg += std::to_string(res.y_reciever); msg += "\"}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, obj_rcvd);
        break;
    case CANCEL_RES: 
        msg += "{}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, cancel);
        break;
    case TIMEOUT_RES:
        msg += "{}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, timeout);
        break;
    case ARRIVED_RES:
        msg += "{\"x_sender\":\""; msg += std::to_string(res.x_sender); msg += "\",\"y_sender\":\""; 
        msg += std::to_string(res.y_sender); msg += "\",\"x_reciever\":\""; msg += std::to_string(res.x_reciever); 
        msg += "\",\"y_reciever\":\""; msg += std::to_string(res.y_reciever); msg += "\"}";
        ROS_INFO_STREAM(msg);
        mtr.send_msg(msg, arrived);
        break;
    default:
        ROS_INFO_STREAM("INVALID_RES_TYPE" << res);
        break;
    }
}