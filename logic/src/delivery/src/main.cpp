#include <ros/ros.h>
#include <vector>
#include <agents_lib/bot.h>
#include <agents_lib/user.h>

#include "delivery/NewGoal.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>

#include <unistd.h>
#include <sstream>

#define T 10

using namespace ros;

//Global vars
geometry_msgs::PoseStamped new_goal_msg;
tf2_ros::Buffer tf_buffer;
int msgs_published = 0;
//boolean to prevent publishing new goal more than once 
bool isPub = false;

std::vector<float> target_position(0,0);
std::vector<float> cur_position(2,0);
std::vector<float> old_position(2,0);
std::vector<float> caller_position(3,0);
std::vector<float> reciever_position(0,0);

void SetGoal_CallBack(const delivery::NewGoal& new_goal);
void Position_CallBack(const tf2_msgs::TFMessage & tf);
void isMoving_CallBack(const ros::TimerEvent& e);
void timeOut_CallBack(const ros::TimerEvent& e);

int main(int argc, char **argv){
    
    ros::init(argc,argv,"delivery");
    ros::NodeHandle n; 
    ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1000);

    tf2_ros::TransformListener tfListener(tf_buffer);

    ros::Subscriber sub_ng = n.subscribe("New_Goal", 1000, SetGoal_CallBack);
    ros::Subscriber sub_tf = n.subscribe("tf", 1000, Position_CallBack);

    ros::Timer t2 = n.createTimer(ros::Duration(50), timeOut_CallBack);
    ros::Timer t1 = n.createTimer(ros::Duration(50), isMoving_CallBack);

    ros::Rate loop_rate(T);
    int count = 0;

    while(ros::ok()){

        //Add a list containing logged in users, when the first user logs in
        //go from status.IDLE to status.waiting

        if(!isPub){
            ROS_INFO("Publishing new Goal");
            pub.publish(new_goal_msg);
            isPub = false;
        }

        ros::spinOnce();
        loop_rate.sleep();
        count++;
        
    }

    return EXIT_SUCCESS;

}


void SetGoal_CallBack(const delivery::NewGoal& new_goal){
    new_goal_msg.header.seq = msgs_published;
    msgs_published++;

    new_goal_msg.header.frame_id = "map";
    new_goal_msg.pose.position.x = new_goal.x;
    new_goal_msg.pose.position.y = new_goal.y;
    new_goal_msg.pose.position.z = 0;

    new_goal_msg.pose.orientation.x = 0;
    new_goal_msg.pose.orientation.y = 0;
    new_goal_msg.pose.orientation.z = 0;
    new_goal_msg.pose.orientation.w = new_goal.theta;

    status = COLLECTING;
    
    isPub = true;

    target_position[0] = new_goal_msg.pose.position.x;
    target_position[1] = new_goal_msg.pose.position.y;

}
void Position_CallBack(const tf2_msgs::TFMessage & tf){
   
}

void isMoving_CallBack(const ros::TimerEvent& e){

}

void timeOut_CallBack(const ros::TimerEvent& e){

}