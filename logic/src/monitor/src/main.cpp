#include "srv_monitor_lib/srv_monitor.h"
#include "srv_monitor_lib/message_creator.h"

#include <ros/ros.h>
#include <unistd.h>
#include <sstream>

#include "monitor/req.h"
#include "std_msgs/String.h"

using namespace ros;

void currentOdomCallback();
void act(req request_);
req getReq(req_parser &parser, srv_monitor &monitor);

int main(int argc, char **argv){
    
    ros::init(argc,argv,"monitor");
    ros::NodeHandle n; 

    ros::Rate loop_rate(50);
    int count = 0;

    //Create monitor and parser
    req_parser parser;
    srv_monitor monitor = srv_monitor();

    //publish on newgoal topic

    ros::Publisher requests_pub = n.advertise <std_msgs::String>("req", 1000);

    while(ros::ok()){

        act(getReq(parser, monitor));

        ros::spinOnce();
        loop_rate.sleep();
        count++;
        
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