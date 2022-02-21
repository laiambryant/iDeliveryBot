#include "../include/srv_monitor_lib/srv_monitor.h"

srv_monitor::srv_monitor(){
    msg_factory = message_creator();
    _srv_comm = Client();
}

srv_monitor::srv_monitor(int port){
    msg_factory = message_creator();
    _srv_comm = Client(port);
}

void srv_monitor::send_msg(string msg, msg_type type){
    //This check is just in case I wanted to implement concurrency to avoid reading
    //and writing at the same time by more than 1 thread or proc
    while(this->_r_OR_w==true){;}

    this->_r_OR_w = true;
    _srv_comm.monitor_write(msg_factory.create(msg, type));
    this->_r_OR_w = false;

}

string srv_monitor::get_msg(){
    //This check is just in case I wanted to implement concurrency to avoid reading
    //and writing at the same time by more than 1 thread or proc
    while(this->_r_OR_w==true){;}

    this->_r_OR_w = true;
    string ret = _srv_comm.monitor_read();
    this->_r_OR_w = false;
    
    return ret;
}

void srv_monitor::monitor_metadata(ostream &stream){
       
}
