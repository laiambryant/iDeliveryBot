#include "body_types.h"

#include <iostream>

using std::string;

int main(int argc, char const *argv[]){
    
    string msg = "[0,LOGIN]:User:{username:aUsername,password:aPassword}";
    generic_body generic = generic_body(msg);

    login_body login = login_body(msg);
    login.parse();
    login.print(cerr);

    //[1,CALL]:{coordinates:{x:0.0,y:1.0,z:2.0},robot_id:666}
    string call_str = "[10,CALL]:{coordinates:{x:0.0,y:1.0,z:2.0},robot_id:111}";
    call_body call = call_body(call_str);
    call.parse();
    call.print(cerr);

    string p_call_str = "[100,PRIORITY_CALL]:{coordinates:{x:1.1,y:1.33,z:2.6},robot_id:222}";
    priority_call_body p_call = priority_call_body(p_call_str);
    p_call.parse();
    p_call.print(cerr);

    string arrived =  "[1000,ARRIVED]:{coordinates:{x:0.6,y:1.6,z:6.0},robot_id:333}";
    arrived_body a_body = arrived_body(arrived);
    a_body.parse();
    a_body.print(cerr);

    string sent = "[800,OBJ_SENT]:{robot_id:444}";
    obj_sent_body sent_body = obj_sent_body(sent);
    sent_body.parse();
    sent_body.print(cerr);

    string rcvd = "[912,OBJ_RCVD]:{robot_id:555}";
    obj_rcvd_body rcv_body = obj_rcvd_body(rcvd);
    rcv_body.parse();
    rcv_body.print(cerr);

    string cancel = "[213,CANCEL]:{robot_id:666}";
    cancel_body c_body = cancel_body(cancel);
    c_body.parse();
    c_body.print(cerr);

    string timeout = "[213,TIMEOUT]:{robot_id:777}";
    timeout_body t_body = timeout_body(timeout);
    t_body.parse();
    t_body.print(cerr);

    return 0;
}
