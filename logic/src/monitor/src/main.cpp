#include "srv_monitor_lib/srv_monitor.h"
#include "srv_monitor_lib/message_creator.h"

#include <ros/ros.h>
#include <unistd.h>
#include <sstream>

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include "monitor/req.h"
#include "std_msgs/String.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"

#define T 50

using namespace ros;

//Global vars------------------------------------------------------------------------------------------------
tf2_ros::Buffer tf_buffer;
int loops_counter = 0;
int logged_in_users = 0;
int pos_msgs = 0;

//Create monitor and parser
req_parser parser;
srv_monitor mtr = srv_monitor();


//Subscriber Callbacks---------------------------------------------------------------------------------------

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf);

//Timer Callbacks--------------------------------------------------------------------------------------------



//Other Funcs------------------------------------------------------------------------------------------------

req getReq(req_parser &parser, srv_monitor &monitor);
void act(req request_);

int main(int argc, char **argv){
    
    ros::init(argc,argv,"monitor");
    ROS_INFO("Starting monitor...");
    ros::NodeHandle n; 
    ros::Rate loop_rate(T);
    tf2_ros::TransformListener tfListener(tf_buffer);

//Publishers-------------------------------------------------------------------------------------------------

    ros::Publisher requests_pub = n.advertise <std_msgs::String>("req", 1000);

//Subscribers------------------------------------------------------------------------------------------------

    ros::Subscriber sub_tf = n.subscribe("tf", 1, send_robot_pos_callback);

//Timers-----------------------------------------------------------------------------------------------------

    while(ros::ok()){  
    
        ROS_INFO("Fetching request...");
    
        act(getReq(parser,mtr));    
    
        ROS_INFO("Recieved msg from clients...");

        ros::spinOnce();
        loop_rate.sleep();
        loops_counter++;
    
    }   

    return EXIT_SUCCESS;

}

req getReq(req_parser &parser, srv_monitor &monitor){

        string login_str = monitor.get_msg();
        std::cerr << login_str << std::endl;
        msg_type type = parser.get_msg_type(login_str);
        string body = parser.get_msg_body(login_str);
        int req_no = parser.get_req_no(login_str);

        //late binding for body
        return req(req_no, body, type, parser.cvt_msg_type_toString(type));
        
}

void act(req request_){

    std::stringstream ss;

    switch (request_.get_type()){
        case login:
            ROS_INFO("Login handler");
            request_.print_metadata(std::cerr);
            if(logged_in_users>0){
                
            }
            break;
        case call:
            ROS_INFO("Call handler");
            request_.print_metadata(std::cerr);
            break;            
        case priority_call:
            ROS_INFO("P_Call handler");
            request_.print_metadata(std::cerr);
            break;
        case arrived:
            ROS_INFO("Arrived handler");
            request_.print_metadata(std::cerr);
            break;
        case obj_sent:
            ROS_INFO("Obj_sent handler");
            request_.print_metadata(std::cerr);
            break;
        case obj_rcvd:
            ROS_INFO("Obj_rcvd handler");
            request_.print_metadata(std::cerr);
            break;
        case cancel:
            ROS_INFO("Cancel handler");
            request_.print_metadata(std::cerr);
            break;
        case timeout:
            ROS_INFO("Timeout handler");
            request_.print_metadata(std::cerr);
            break;
        default:
            ROS_INFO("Default handler ");
            request_.print_metadata(std::cerr);
            break;
    }

}

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf){
    bool can_transf = tf_buffer.canTransform("map", "base_link", ros::Time(0));
    if(can_transf){
        geometry_msgs::TransformStamped tr_stamped;
        tr_stamped = tf_buffer.lookupTransform("map", "base_link", ros::Time(0));

        //ROS_INFO_STREAM("Position x:" << tr_stamped.transform.translation.x);
        //ROS_INFO_STREAM("Position y:" << tr_stamped.transform.translation.y);
        //ROS_INFO_STREAM("Orientation w:" << tr_stamped.transform.rotation.w);

        double x_pos = tr_stamped.transform.translation.x;
        double y_pos = tr_stamped.transform.translation.y;
        double orientation = tr_stamped.transform.rotation.w;

        string msg; msg += "["; msg += std::to_string(pos_msgs); msg += "]:{x_pos:"; msg += std::to_string(x_pos); msg += ",y_pos:"; msg += std::to_string(y_pos); msg += "}";

        mtr.send_msg(msg, robo_pos);

        ROS_INFO_STREAM(msg);

   }
}