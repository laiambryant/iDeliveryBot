#include "srv_monitor/srv_monitor.h"
#include "srv_monitor/message_creator.h"
#include "ros/ros.h"

#define DEBUG false

using namespace ros;

ros::Publisher pub;

int main(int argc, char **argv){
    
    ros::init(argc, argv, "iDelivery_bot_logic");
    ros::NodeHandle n;

    req_parser parser; string str;
    srv_monitor monitor = srv_monitor();

    while(ros::ok()){

        str = monitor.get_msg();
        msg_type type = parser.get_msg_type(str);
        string body = parser.get_msg_body(str);
        int req_no = parser.get_req_no(str);

        //late binding for body
        req login_request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
        if(DEBUG) login_request.print_metadata(cerr);
        login_request.act();

    }


    return 0;
}
