#pragma once
#include <iostream>
#include <ros/ros.h>

#include "req_parser.h"
#include "req.h"

using std::string;

class message_creator{
private:
    int _msg_no;
    req_parser _parser;
public:
//CTORS--------------------------------------------------------------------------------------------------

    message_creator():_msg_no(0), _parser(){}

//FUNCS--------------------------------------------------------------------------------------------------

    string create(string msg, msg_type msg_type);
};