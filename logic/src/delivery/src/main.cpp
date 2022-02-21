#include <ros/ros.h>
#include <agents_lib/bot.h>
#include <agents_lib/user.h>
#include <agents_lib/utils.h>

#include "delivery/NewGoal.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include "delivery/Req.h"
#include "delivery/Res.h"

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

#include <unistd.h>
#include <sstream>
#include <vector>

#define T 1
#ifndef REQ_NUMS
    #define CALL_REQ 1
    #define SEND_REQ 2
    #define RCVD_REQ 3
    #define CANCEL_REQ 4
    #define TIMEOUT_REQ 5
#endif
#ifndef RES_NUMS
    #define CALL_RES 1
    #define SEND_RES 2
    #define RCVD_RES 3
    #define CANCEL_RES 4
    #define TIMEOUT_RES 5
    #define ARRIVED_RES 6
#endif

using namespace ros;
using coords = std::vector<float>;
using bots = std::vector<bot>;
using users = std::vector<user>;

//Global vars------------------------------------------------------------------------------------------------

int msgs_published = 0;
bool isPub = false; //boolean to prevent publishing new goal more than once 
tf2_ros::Buffer tf_buffer;

//Messages---------------------------------------------------------------------------------------------------
geometry_msgs::PoseStamped new_goal_msg;
delivery::Res res_msg;

//Publishers-------------------------------------------------------------------------------------------------
ros::Publisher pub_res;
ros::Publisher pub_goal;

//Agents-----------------------------------------------------------------------------------------------------

bots bot_list; bot robot_1 = bot(); bot* robot1_ptr = &robot_1;

//Subscriber Callbacks---------------------------------------------------------------------------------------

void SetGoal_CallBack(const delivery::NewGoal& new_goal);
void Position_CallBack(const tf2_msgs::TFMessage & tf);
void Request_CallBack(const delivery::Req & Req);

//Timer Callbacks--------------------------------------------------------------------------------------------

void isMoving_CallBack(const ros::TimerEvent& e);
void timeOut_CallBack(const ros::TimerEvent& e);

//INTENT(s)--------------------------------------------------------------------------------------------------

void pursue_goal(float x, float y, float w);
void call_handler(float x, float y, float w);
void send_handler(float x, float y, float w);
void timeout_handler();
void cancel_handler();

//Responses--------------------------------------------------------------------------------------------------

void call_res_pub(float x, float y, float w);
void send_res_pub(float x, float y, float w);
void delivered_res_pub();
void cancel_res_pub();
void timeOut_res_pub();
void arrived_res_pub();

int main(int argc, char **argv){
    
    ros::init(argc,argv,"delivery");
    ros::NodeHandle n; 
    ROS_INFO("Delivery node starting...");
    tf2_ros::TransformListener tfListener(tf_buffer);
    ros::Rate loop_rate(T);
    int count = 0;

//Publishers-------------------------------------------------------------------------------------------------

    pub_goal = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);
    pub_res = n.advertise<delivery::Res>("/Res", 1000);

//Subscribers------------------------------------------------------------------------------------------------

    ros::Subscriber sub_ng = n.subscribe("NewGoal", 1000, SetGoal_CallBack);
    ros::Subscriber sub_tf = n.subscribe("tf", 10, Position_CallBack);
    ros::Subscriber sub_req = n.subscribe("Req", 1, Request_CallBack);

//Timers-----------------------------------------------------------------------------------------------------

    ros::Timer t2 = n.createTimer(ros::Duration(100), timeOut_CallBack);
    ros::Timer t1 = n.createTimer(ros::Duration(0.5), isMoving_CallBack);

    while(ros::ok()){

        if(isPub){
            ROS_INFO("Publishing new Goal");
            pub_goal.publish(new_goal_msg);
            isPub = false;
        }

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
        
    }

    return EXIT_SUCCESS;

}

void SetGoal_CallBack(const delivery::NewGoal& new_goal){

    ROS_INFO_STREAM("Recieved new goal:{x: " 
        << new_goal.x << ", y: "
        << new_goal.y << std::endl);

    pursue_goal(new_goal.x, new_goal.y, new_goal.theta);

}
void Position_CallBack(const tf2_msgs::TFMessage & tf){
    
   bool can_transf = tf_buffer.canTransform("map", "base_link", ros::Time(0));
   if(can_transf){
       
        geometry_msgs::TransformStamped tr_stamped;
        tr_stamped = tf_buffer.lookupTransform("map", "base_link", ros::Time(0));

        robot1_ptr->set_old_pos(robot1_ptr->get_pos());
        robot1_ptr->update_pos(tr_stamped.transform.translation.x, tr_stamped.transform.translation.y);

   }

}
void isMoving_CallBack(const ros::TimerEvent& e){

    bot_status s = robot1_ptr->get_status();
    coords old_pos, curr_pos, target_pos; 
    old_pos = robot1_ptr->get_old_pos(); curr_pos = robot1_ptr->get_pos(); target_pos = robot1_ptr->get_curr_obj();

    if(s==COLLECTING||s==RETURNING||s==DELIVERING){
        ROS_INFO("Checking if robot is moving");
        float inv_dst = Id_SW_SqrtLinear((pow(curr_pos[0]-old_pos[0],2)+pow(curr_pos[1]-old_pos[1],2))); 
        if(inv_dst < 1.25) {
            ROS_INFO_STREAM("Robot is stuck at x:" << curr_pos[0] << " , y:" << curr_pos[1]);
        }
        float inv_dst_from_goal = Id_SW_SqrtLinear((pow(curr_pos[0]-target_pos[0],2)+pow(curr_pos[1]-target_pos[1],2)));
        if(inv_dst_from_goal > 0.666){
            ROS_INFO_STREAM("Robot arrived at x:" << curr_pos[0] << " , y:" << curr_pos[1]);
            if(s==COLLECTING){
                robot1_ptr->set_status(WAITING);
            }
            if(s==RETURNING || s == DELIVERING){
                robot1_ptr->set_status(IDLE);
            }
            arrived_res_pub();
        }
    }
}
void timeOut_CallBack(const ros::TimerEvent& e){
    bot_status s = robot1_ptr->get_status();
    if(s==COLLECTING||s==RETURNING||s==DELIVERING||s==WAITING){
        timeout_handler();
    }
}
void Request_CallBack(const delivery::Req & Req){
    switch (Req.type){
        case CALL_REQ: 
            ROS_INFO("Call Request incoming");
            call_handler(Req.x, Req.y, Req.w);
            break;
        case SEND_REQ:
            ROS_INFO("Send Request incoming");
            send_handler(Req.x, Req.y, Req.w);
            break;
        case RCVD_REQ: 
            ROS_INFO("Object Recieved Request incoming");
            delivered_res_pub();
            break;
        case CANCEL_REQ: 
            ROS_INFO("Cancel Request incoming");
            cancel_handler();
            break;
        case TIMEOUT_REQ:
            ROS_INFO("Timeout Request incoming");
            timeout_handler();
            break;
        default:
            ROS_INFO_STREAM("ERROR: Invalid type_no");
            break;
    }
}

void pursue_goal(float x, float y, float w){

    new_goal_msg.header.seq = msgs_published;
    msgs_published++;

    new_goal_msg.header.stamp = ros::Time::now();
    new_goal_msg.header.frame_id = "map";
    new_goal_msg.pose.position.x = x;
    new_goal_msg.pose.position.y = y;
    new_goal_msg.pose.position.z = 0;

    new_goal_msg.pose.orientation.x = 0;
    new_goal_msg.pose.orientation.y = 0;
    new_goal_msg.pose.orientation.z = 0;
    new_goal_msg.pose.orientation.w = w;
    
    coords old_objective = robot1_ptr->get_curr_obj();
    robot1_ptr->set_old_obj(old_objective[0], old_objective[1]);
    robot1_ptr->set_curr_obj(x, y);

    isPub = true;

}

void call_handler(float x, float y, float w){
    bot_status s = robot1_ptr->get_status();
    if(s==COLLECTING||s==DELIVERING){
        ROS_INFO("Cannot pursue goal, Robot is buisy");
    } else {
        robot1_ptr->set_status(COLLECTING);
        pursue_goal(x,y,w);
        call_res_pub(x,y,w);
    }
}
void send_handler(float x, float y, float w){
    bot_status s = robot1_ptr->get_status();
    if(s==COLLECTING||s==DELIVERING){
        ROS_INFO("Cannot pursue goal, Robot is buisy");
    } else {
    robot1_ptr->set_status(DELIVERING);
    pursue_goal(x,y,w);
    send_res_pub(x,y,w);
    }
}
void timeout_handler(){
    bot_status s = robot1_ptr->get_status();
    coords curr_pos = robot1_ptr->get_pos(); coords target_pos = robot1_ptr->get_curr_obj();
    if(s==COLLECTING||s==RETURNING||s==DELIVERING||s==WAITING){
        float inv_dst_from_goal = Id_SW_SqrtLinear((pow(curr_pos[0]-target_pos[0],2)+pow(curr_pos[1]-target_pos[1],2)));
        if(inv_dst_from_goal > 2){
            ROS_INFO("Timeout: Goal point could not be reached on time");
            if(s==COLLECTING){
                //If robot is collecting item or waiting for item to be accepted by reciever and there is a timeout 
                coords stop_pos = robot1_ptr->get_pos();
                pursue_goal(stop_pos[0]-0.5, stop_pos[1]-0.5, 0.0);
                timeOut_res_pub();
                robot1_ptr->set_status(IDLE);
            }else if(s==DELIVERING||s==RETURNING||s==WAITING){
                //If robot is delivering, waiting or if request has been cancelled while delivering robot returns to user's position
                coords old_obj = robot1_ptr->get_old_obj();
                pursue_goal(old_obj[0], old_obj[1], 0.0);
                timeOut_res_pub();
                robot1_ptr->set_status(RETURNING);
            }
        }
    }
}
void cancel_handler(){
    bot_status s = robot1_ptr->get_status();
    ROS_INFO("Cancel: sender cancelled delivery");
        if(s==COLLECTING){
            //If robot is collecting item or waiting for item to be accepted by reciever and there is a timeout 
            robot1_ptr->set_status(CANCELLING);
            coords stop_pos = robot1_ptr->get_pos();
            pursue_goal(stop_pos[0], stop_pos[1], 0.0);
            cancel_res_pub();
            robot1_ptr->set_status(IDLE);
        }else if(s==DELIVERING||s==RETURNING||s==WAITING){
            //If robot is delivering or request has been cancelled while delivering robot returns to user's position
            robot1_ptr->set_status(CANCELLING);
            coords old_obj = robot1_ptr->get_old_obj();
            pursue_goal(old_obj[0], old_obj[1], 0.0);
            cancel_res_pub();
            robot1_ptr->set_status(RETURNING);
        }
}

void call_res_pub(float x, float y, float w){
    ROS_INFO("Sending CALL Res");
    res_msg.type = CALL_RES;
    res_msg.x_sender=x;
    res_msg.y_sender=y;
    res_msg.x_reciever=0.0;
    res_msg.x_reciever=0.0;
    pub_res.publish(res_msg);
}
void send_res_pub(float x, float y, float w){
    ROS_INFO("Sending SEND res");
    coords sender_coords = robot1_ptr->get_old_obj();
    res_msg.type = SEND_RES;
    res_msg.x_sender=sender_coords[0];
    res_msg.y_sender=sender_coords[1];
    res_msg.x_reciever=x;
    res_msg.x_reciever=y;
    pub_res.publish(res_msg);
}
void delivered_res_pub(){ 
    ROS_INFO("Sending DELIVERED res");
    coords sender_coords = robot1_ptr->get_old_obj();
    coords reciever_coords = robot1_ptr->get_curr_obj();
    res_msg.type = RCVD_RES;
    res_msg.x_sender=sender_coords[0];
    res_msg.y_sender=sender_coords[1];
    res_msg.x_reciever=reciever_coords[0];
    res_msg.x_reciever=reciever_coords[1];
    pub_res.publish(res_msg);
}
void cancel_res_pub(){
    ROS_INFO("Sending CANCEL res");
    res_msg.type = CANCEL_RES;
    res_msg.x_sender=0.0;
    res_msg.y_sender=0.0;
    res_msg.x_reciever=0.0;
    res_msg.x_reciever=0.0;
    pub_res.publish(res_msg);
}
void timeOut_res_pub(){
    ROS_INFO("Sending TIMEOUT res");
    res_msg.type = TIMEOUT_RES;
    res_msg.x_sender=0.0;
    res_msg.y_sender=0.0;
    res_msg.x_reciever=0.0;
    res_msg.x_reciever=0.0;
    pub_res.publish(res_msg);
}
void arrived_res_pub(){
    ROS_INFO("Sending ARRIVED res");
    coords sender_coords = robot1_ptr->get_old_obj();
    coords reciever_coords = robot1_ptr->get_curr_obj();
    res_msg.type = ARRIVED_RES;
    res_msg.x_sender=sender_coords[0];
    res_msg.y_sender=sender_coords[1];
    res_msg.x_reciever=reciever_coords[0];
    res_msg.x_reciever=reciever_coords[1];
    pub_res.publish(res_msg);
}