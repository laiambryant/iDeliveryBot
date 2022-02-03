#include "srv_monitor_lib/srv_monitor.h"
#include "srv_monitor_lib/message_creator.h"

#include <ros/ros.h>
#include <unistd.h>
#include <sstream>
#include <array>

#include <tf2_ros/transform_listener.h>
#include <tf2_msgs/TFMessage.h>
#include "delivery/NewGoal.h"
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
ros::Publisher pub_NGoal;

//Create monitor and parser
req_parser parser;
srv_monitor mtr = srv_monitor(5000);

//Subscriber Callbacks---------------------------------------------------------------------------------------

void send_robot_pos_callback(const tf2_msgs::TFMessage &tf);

//Timer Callbacks--------------------------------------------------------------------------------------------



//Other Funcs------------------------------------------------------------------------------------------------
void c_handler(float x_, float y_, float w_);
void canc_handler();
void recv_handler();

req getReq(req_parser &parser, srv_monitor &monitor);
void act(req request_);

int main(int argc, char **argv){

    ros::init(argc,argv,"monitor");
    ROS_INFO("Starting monitor...");
    
    ros::NodeHandle n; 
    ros::Rate loop_rate(T);
    tf2_ros::TransformListener tfListener(tf_buffer);

//Publishers-------------------------------------------------------------------------------------------------

    pub_NGoal = n.advertise<delivery::NewGoal>("/NewGoal", 1000);
 
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
    coordinates_3D location;

    switch (request_.get_type()){
        case login:
            ROS_INFO("Login handler");
            request_.print_metadata(std::cerr);
            break;
        case call:
            ROS_INFO("Call handler");
            request_.print_metadata(std::cerr);
            location = request_.get_body()->get_coords();
            c_handler(location[0], location[1], 0.0);
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
            recv_handler();
            break;
        case cancel:
            ROS_INFO("Cancel handler");
            request_.print_metadata(std::cerr);
            canc_handler();
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


void c_handler(float x_, float y_, float w_){
    delivery::NewGoal m;
    m.x = x_; m.y = y_; m.theta = w_;
    pub_NGoal.publish(m);
}
void canc_handler(){

}
void recv_handler(){

}