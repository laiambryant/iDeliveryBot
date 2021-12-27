#include "srv_monitor_lib/message_creator.h"
#include "srv_monitor_lib/srv_monitor.h"

#include <ros/ros.h>
#include "callbacks.h"

#include <unistd.h>

using namespace ros;

void currentOdomCallback();

int main(int argc, char **argv){
    
    ros::init(argc,argv,"delivery");
    ros::NodeHandle n; 

    req_parser parser; string login_str;
    srv_monitor monitor = srv_monitor();

    ros::Rate loop_rate(10);
    int count = 0;

    pid_t monitor_pid = fork();
    if(monitor_pid<0){ perror("fork");exit(EXIT_FAILURE);}

    if (monitor_pid > 0){
    //Monitor process
        while(ros::ok()){
            login_str = monitor.get_msg();
            msg_type type = parser.get_msg_type(login_str);
            string body = parser.get_msg_body(login_str);
            int req_no = parser.get_req_no(login_str);

            //late binding for body
            req login_request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
            login_request.print_metadata(cerr);
            login_request.act();
        }
    } else {
    //Ros process
        while(ros::ok()){

            ros::spinOnce();
            loop_rate.sleep();
            count++;
            
        }
    }

    return EXIT_SUCCESS;
}

