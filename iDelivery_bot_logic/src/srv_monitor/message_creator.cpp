#include "message_creator.h"

message_creator::message_creator():_msg_no(0){}

string message_creator::create(string msg){
    string tmp;
    tmp += "["; tmp+= _msg_no; tmp += "]:";
    tmp += msg; tmp+= "\n";
    _msg_no++; return tmp;
}
