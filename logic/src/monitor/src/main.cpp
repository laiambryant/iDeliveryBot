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
#include "delivery/Req.h"

#define T 50
#ifndef REQ_NUMS
    #define CALL_REQ 1
    #define SEND_REQ 2
    #define RCVD_REQ 3
    #define CANCEL_REQ 4
    #define TIMEOUT_REQ 5
#endif

using namespace ros;

//Global vars------------------------------------------------------------------------------------------------
tf2_ros::Buffer tf_buffer;

int loops_counter = 0;
int logged_in_users = 0;
int pos_msgs = 0;
coordinates_3D curr_bot_pos;

ros::Publisher pub_NGoal;
ros::Publisher pub_NMsg;

//Create monitor and parser
req_parser parser;
srv_monitor mtr = srv_monitor(5000);

//Subscriber Callbacks---------------------------------------------------------------------------------------

//Timer Callbacks--------------------------------------------------------------------------------------------


//Other Funcs------------------------------------------------------------------------------------------------

void c_handler(float x_, float y_, float w_);
req getReq(req_parser &parser, srv_monitor &monitor);
void act(req request_);
void publish_request(int type, int r_id, float x, float y, float w);


int main(int argc, char **argv){

    ros::init(argc,argv,"monitor");
    ROS_INFO("Starting monitor...");
    
    ros::NodeHandle n; 
    ros::Rate loop_rate(T);

//Subscribers------------------------------------------------------------------------------------------------


//Publishers-------------------------------------------------------------------------------------------------

    pub_NGoal = n.advertise<delivery::NewGoal>("/NewGoal", 1000);
    pub_NMsg = n.advertise<delivery::Req>("/Req", 1000);
 
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
        case call: //1
            ROS_INFO("Call handler");
            request_.print_metadata(std::cerr);
            location = request_.get_body()->get_coords();
            c_handler(location[0], location[1], 0.0);
            publish_request(CALL_REQ, 1, location[0], location[1], 0.0);
            break;            
        case obj_send: //2
            ROS_INFO("Obj_sent handler");
            request_.print_metadata(std::cerr);
            location = request_.get_body()->get_coords();
            publish_request(SEND_REQ, 1, location[0], location[1], 0.0);
            break;
        case obj_rcvd: //3
            ROS_INFO("Obj_rcvd handler");
            request_.print_metadata(std::cerr);
            location = request_.get_body()->get_coords();
            publish_request(RCVD_REQ, 1, location[0], location[1], 0.0);
            break;
        case cancel: //4
            ROS_INFO("Cancel handler");
            request_.print_metadata(std::cerr);
            publish_request(CANCEL_REQ, 1, 0.0, 0.0, 0.0);
            break;
        case timeout: //5
            ROS_INFO("Timeout handler");
            request_.print_metadata(std::cerr);
            publish_request(CANCEL_REQ, 1, 0.0, 0.0, 0.0);
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

void publish_request(int type, int r_id, float x, float y, float w){
    delivery::Req m;
    m.type = type; m.r_id = r_id; m.x = x; m.y = y; m.w = w;
    pub_NMsg.publish(m);
}