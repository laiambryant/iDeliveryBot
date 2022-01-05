#include "srv_monitor_lib/srv_monitor.h"
#include "srv_monitor_lib/message_creator.h"

#include <ros/ros.h>
#include <unistd.h>

using namespace ros;

void currentOdomCallback();

int main(int argc, char **argv){
    
    ros::init(argc,argv,"monitor");
    ros::NodeHandle n; 

    ros::Rate loop_rate(10);
    int count = 0;

    //Create monitor and parser
    req_parser parser;
    srv_monitor monitor = srv_monitor();
    string login_str;

    while(ros::ok()){

        login_str = monitor.get_msg();
        msg_type type = parser.get_msg_type(login_str);
        string body = parser.get_msg_body(login_str);
        int req_no = parser.get_req_no(login_str);

        //late binding for body
        req login_request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
        login_request.print_metadata(cerr);
        login_request.act();

        ros::spinOnce();
        loop_rate.sleep();
        count++;
        
    }

    return EXIT_SUCCESS;

}
