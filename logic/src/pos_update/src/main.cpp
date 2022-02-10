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

#define T 1000

using namespace ros;

//Global vars------------------------------------------------------------------------------------------------
tf2_ros::Buffer tf_buffer;
int loops_counter = 0;
int logged_in_users = 0;
int pos_msgs = 0;

//Create monitor and parser
req_parser parser;
srv_monitor mtr = srv_monitor(5050);

//Subscriber Callbacks---------------------------------------------------------------------------------------

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf);

int main(int argc, char **argv){

    ros::init(argc,argv,"pos_update");
    ROS_INFO("Starting updater...");
    
    ros::NodeHandle n; 
    ros::Rate loop_rate(T);
    tf2_ros::TransformListener tfListener(tf_buffer);

//Publishers-------------------------------------------------------------------------------------------------


//Subscribers------------------------------------------------------------------------------------------------

    ros::Subscriber sub_tf = n.subscribe("tf", 1, send_robot_pos_callback);
 
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

        //ROS_INFO_STREAM("Position x:" << tr_stamped.transform.translation.x);
        //ROS_INFO_STREAM("Position y:" << tr_stamped.transform.translation.y);
        //ROS_INFO_STREAM("Orientation w:" << tr_stamped.transform.rotation.w);

        double x_pos = tr_stamped.transform.translation.x;
        double y_pos = tr_stamped.transform.translation.y;
        double orientation = tr_stamped.transform.rotation.w;

        string msg; msg += "{\"x_pos\":\""; msg += std::to_string(x_pos); msg += "\",\"y_pos\":\""; msg += std::to_string(y_pos); msg += "\"}";

        mtr.send_msg(msg, robo_pos);

        ROS_INFO_STREAM(msg);

   }
}