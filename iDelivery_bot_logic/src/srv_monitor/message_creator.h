
#include <iostream>
using std::string;

enum msg_type{
    login, call, priority_call, arrived, obj_sent,
    obj_rcvd, cancel, timeout
};

class message_creator{
private:
    int _msg_no;
    string _msg_type_str[8] = {
        "LOGIN","CALL","PRIORITY CALL","ARRIVED",
        "OBJ_SENT","OBJ_RCVD","CANCEL", "TIMEOUT"
    };
public:
    message_creator():_msg_no(0){}
    string create(string msg, msg_type msg_type);
};