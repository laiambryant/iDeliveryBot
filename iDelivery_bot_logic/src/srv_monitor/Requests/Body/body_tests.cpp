#include "req_body.h"
#include "body_types.h"

#include <iostream>

using std::string;

int main(int argc, char const *argv[]){
    
    string msg = "[0,LOGIN]:User:{username:aUsername,password:aPassword}";
    generic_body generic = generic_body(msg);

    login_body login = login_body(msg);
    login.parse();
    login.print(cerr_out);

    //[1,CALL]:{coordinates:{x:0.0,y:1.0,z:2.0},robot_id:666}
    string call_str = "[10,CALL]:{coordinates:{x:0.0,y:1.0,z:2.0},robot_id:666}";
    call_body call = call_body(call_str);
    call.parse();
    call.print(cerr_out);

    string p_call_str = "[100,PRIORITY_CALL]:{coordinates:{x:1.1,y:1.33,z:2.6},robot_id:111}";
    priority_call_body p_call = priority_call_body(p_call_str);
    p_call.parse();
    p_call.print(cerr_out);

    return 0;
}
