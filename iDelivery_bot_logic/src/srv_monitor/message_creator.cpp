#include "message_creator.h"


string message_creator::create(string msg, msg_type type){
    string tmp;
    tmp += "["; tmp+= std::to_string(_msg_no); 
    tmp += ","; tmp += _msg_type_str[type];
    tmp += "]:";tmp += msg;
    _msg_no++; return tmp;
}
