#pragma once
#include <iostream>
#include <fstream>

#include "Client.h"
#include "message_creator.h"
#include "body_types.h"

#ifndef LOG_PATH
#define LOG_PATH "products/log.txt"
#endif
#define OUT_PATH "products/out.txt"
#define IN_PATH "products/in.txt"

#define MSG_MAX_SIZE 500

using namespace std;
//Monitor creates two streams: one to read one to write
class srv_monitor{

private:
    Client _srv_comm;
    string msg_buf_;
    message_creator msg_factory;
    void clear_msg_buff();
     
public:
    srv_monitor();
    srv_monitor(const srv_monitor &other);
    void send_msg(string msg, msg_type type); //bool write_to_sock(char* msg); 
    string get_msg();  //gets last msg from input_stream
    void monitor_metadata(ostream &stream);

};
