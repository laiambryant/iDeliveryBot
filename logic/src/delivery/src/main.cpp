#include <ros/ros.h>
#include <agents_lib/bot.h>
#include <agents_lib/user.h>
#include <agents_lib/utils.h>

#include "delivery/NewGoal.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include "delivery/Req.h"

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

#include <unistd.h>
#include <sstream>
#include <vector>

#define T 1

using namespace ros;
using coords = std::vector<float>;

//Global vars------------------------------------------------------------------------------------------------

geometry_msgs::PoseStamped new_goal_msg;
tf2_ros::Buffer tf_buffer;
int msgs_published = 0;
bool isPub = false; //boolean to prevent publishing new goal more than once 
bot robot_1 = bot(); bot* robot1_ptr = &robot_1;

//Subscriber Callbacks---------------------------------------------------------------------------------------

void SetGoal_CallBack(const delivery::NewGoal& new_goal);
void Position_CallBack(const tf2_msgs::TFMessage & tf);
void Request_CallBack(const delivery::Req & Req);

//Timer Callbacks--------------------------------------------------------------------------------------------

void isMoving_CallBack(const ros::TimerEvent& e);
void timeOut_CallBack(const ros::TimerEvent& e);

//Other------------------------------------------------------------------------------------------------------

void pursue_goal(float x, float y, float w);

int main(int argc, char **argv){
    
    ros::init(argc,argv,"delivery");
    ros::NodeHandle n; 
    ROS_INFO("Delivery node starting...");
    tf2_ros::TransformListener tfListener(tf_buffer);
    ros::Rate loop_rate(T);
    int count = 0;

//Publishers-------------------------------------------------------------------------------------------------

    ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);

//Subscribers------------------------------------------------------------------------------------------------

    ros::Subscriber sub_ng = n.subscribe("NewGoal", 1000, SetGoal_CallBack);
    ros::Subscriber sub_tf = n.subscribe("tf", 10, Position_CallBack);
    ros::Subscriber sub_req = n.subscribe("Req", 1, Request_CallBack);

//Timers-----------------------------------------------------------------------------------------------------

    ros::Timer t2 = n.createTimer(ros::Duration(100), timeOut_CallBack);
    ros::Timer t1 = n.createTimer(ros::Duration(0.5), isMoving_CallBack);

    while(ros::ok()){

        //Add a list containing logged in users, when the first user logs in go from status.IDLE to status.waiting

        if(isPub){
            ROS_INFO("Publishing new Goal");
            pub.publish(new_goal_msg);
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

        //ROS_INFO_STREAM("Addr: "<< robot1_ptr << "\tx: " << robot1_ptr->get_pos()[0] << ", y:" << robot1_ptr->get_pos()[1]);
        //ROS_INFO_STREAM("TRStamped\tx:"<< tr_stamped.transform.translation.x << "\ty:"<<tr_stamped.transform.translation.y);
   }

}
void isMoving_CallBack(const ros::TimerEvent& e){

    bot_status s = robot1_ptr->get_status();
    coords old_pos, curr_pos, target_pos; 
    old_pos = robot1_ptr->get_old_pos(); curr_pos = robot1_ptr->get_pos(); target_pos = robot1_ptr->get_curr_obj();

    //ROS_INFO_STREAM("Addr: "<< robot1_ptr << "\tx: " << robot1_ptr->get_pos()[0] << ", y:" << robot1_ptr->get_pos()[1]);
    //ROS_INFO_STREAM("Old pos:\t"<< old_pos[0]<<"," << old_pos[1]<<std::endl);

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
        }
    }
}
void timeOut_CallBack(const ros::TimerEvent& e){
    bot_status s = robot1_ptr->get_status();
    coords curr_pos = robot1_ptr->get_pos(); coords target_pos = robot1_ptr->get_curr_obj();
    if(s==COLLECTING||s==RETURNING||s==DELIVERING){
        float inv_dst_from_goal = Id_SW_SqrtLinear((pow(curr_pos[0]-target_pos[0],2)+pow(curr_pos[1]-target_pos[1],2)));
        if(inv_dst_from_goal > 2){
            ROS_INFO("Timeout: Goal point could not be reached on time");
            robot1_ptr->set_status(IDLE);
        }
    }
}
void Request_CallBack(const delivery::Req & Req){
    coords stop_pos = robot1_ptr->get_pos();
    switch (Req.type){
        case 1: //Call
            ROS_INFO("Call Request incoming");
            pursue_goal(Req.x, Req.y, Req.w);
            break;
        case 2: //Send
            ROS_INFO("Send Request incoming");
            pursue_goal(Req.x, Req.y, Req.w);
            break;
        case 3: //Object Recieved
            ROS_INFO("Object Recieved Request incoming");
            break;
        case 4: //Cancel
            ROS_INFO("Cancel Request incoming");
            ROS_INFO("Stopping bot @:%f,%f", stop_pos[0], stop_pos[1]);
            pursue_goal(stop_pos[0]-0.5,stop_pos[1]-0.5, 0.0);
            break;
        case 5: //Timeout
            ROS_INFO("Timeout Request incoming");
            ROS_INFO("Stopping bot @:%f,%f", stop_pos[0], stop_pos[1]);
            pursue_goal(stop_pos[0]-0.5,stop_pos[1]-0.5, 0.0);
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
    isPub = true;

    robot1_ptr->set_status(COLLECTING);
    robot1_ptr->set_curr_obj(x, y);

}