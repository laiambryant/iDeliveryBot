#include "srv_monitor.h"

srv_monitor::srv_monitor(){
    msg_factory = message_creator();
    _srv_comm = Client();
}


void srv_monitor::send_msg(string msg, msg_type type){
    _srv_comm.monitor_write( msg_factory.create(msg, type));
}


string srv_monitor::get_msg(){
    string ret = _srv_comm.monitor_read();
    return ret;
}


void srv_monitor::monitor_metadata(ostream &stream){
       
}
