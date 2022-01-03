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
    
    while(ros::ok()){

        ros::spinOnce();
        loop_rate.sleep();
        count++;
        
    }

    return EXIT_SUCCESS;

}
