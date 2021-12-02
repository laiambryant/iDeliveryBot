#include "req_body.h"

void generic_body::parse(){}

void login_body::parse(){
    //[0,LOGIN]:User:{username:aUsername,password:aPassword}
    string u_field_str = "username:"; string p_field_str = "password:";
    _username = my_substr(_body_str , u_field_str, ",");
    _password = my_substr(_body_str, p_field_str, "}");
}

void r_id_body::parse(){
    //[0,OBJ_SENT]:{robot_id:666}
    string r_id_field_str = "robot_id:";
    _robot_id = stoi(_body_str.substr(_body_str.find(r_id_field_str)+r_id_field_str.length(),3));
}

void coord_body::parse(){
    //[0,CALL]:{coordinates:{x:0.0,y:1.0,z:2.0},robot_id:666}
    string r_id_field_str = "robot_id:";
    float x = stof(my_substr(_body_str, "x:", ",y"));
    float y = stof(my_substr(_body_str, "y:", ",z"));
    float z = stof(my_substr(_body_str, "z:", "},"));
    _coordinates = {x,y,z};
    _robot_id = stoi(_body_str.substr(_body_str.find(r_id_field_str)+r_id_field_str.length(),3));
}
