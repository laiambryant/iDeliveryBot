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

int main(int argc, char **argv){
    
    ros::init(argc,argv,"monitor");
    ros::NodeHandle n; 

    ros::Rate loop_rate(50);
    int count = 0;

    //Create monitor and parser
    req_parser parser;
    srv_monitor monitor = srv_monitor();
    string login_str;

    ros::Publisher requests_pub = n.advertise <std_msgs::String>("req", 1000);

    while(ros::ok()){

        login_str = monitor.get_msg();
        msg_type type = parser.get_msg_type(login_str);
        string body = parser.get_msg_body(login_str);
        int req_no = parser.get_req_no(login_str);

        //late binding for body
        req request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
        act(request);

        ros::spinOnce();
        loop_rate.sleep();
        count++;
        
    }

    return EXIT_SUCCESS;

}

void act(req request_){

    monitor::req req_msg;
    std::stringstream ss;

    switch (request_.get_type()){
        case login:
            ROS_INFO("Login handler");
            break;
        case call:
            ROS_INFO("Call handler");
            break;            
        case priority_call:
            ROS_INFO("P_Call handler");
            break;
        case arrived:
            ROS_INFO("Arrived handler");
            break;
        case obj_sent:
            ROS_INFO("Obj_sent handler");
            break;
        case obj_rcvd:
            ROS_INFO("Obj_rcvd handler");
            break;
        case cancel:
            ROS_INFO("Cancel handler");
            break;
        case timeout:
            ROS_INFO("Timeout handler");
            break;
        default:
            ROS_INFO("Default handler");
            break;
    }
}