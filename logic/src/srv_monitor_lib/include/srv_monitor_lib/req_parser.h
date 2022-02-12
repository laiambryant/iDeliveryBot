#pragma once
#include <iostream>
#include <map>
#include <ros/ros.h>

#ifndef LOG_PATH
#define LOG_PATH "products/log_req.txt"
#endif

#ifndef MSG_TYPE
#define MSG_TYPE
enum msg_type{
    login, call, obj_send,
    obj_rcvd, cancel, timeout, invalid, robo_pos
};
#endif


using namespace std;

class req_parser{

private:
    map<string, msg_type> s_mapMsgType;
    string _msg_type_string[8] = {
        "LOGIN","CALL","SEND","OBJ_RCV",
        "CANCEL","TIMEOUT", "INVALID", "ROBO_POS"
    };
    
    //FUNCS--------------------------------------------------------------------------------------------------

    void _msg_map_init(){   
        s_mapMsgType["LOGIN"] = login;
        s_mapMsgType["CALL"] = call;
        s_mapMsgType["SEND"] = obj_send;
        s_mapMsgType["OBJ_RCV"] = obj_rcvd;
        s_mapMsgType["CANCEL"] = cancel;
        s_mapMsgType["TIMEOUT"] = timeout;
        s_mapMsgType["INVALID"] = invalid;
        s_mapMsgType["ROBO_POS"] = robo_pos;
    }

    
public:
//CTORS--------------------------------------------------------------------------------------------------

    req_parser(){_msg_map_init();}
    ~req_parser(){}

//GETTERS------------------------------------------------------------------------------------------------

    int get_req_no(string req);
    msg_type get_msg_type(string req);
    string get_msg_body(string req);

//FUNCS--------------------------------------------------------------------------------------------------

    string cvt_msg_type_toString(msg_type type);
    msg_type cvt_string_toMsgType(string type_string);
};

