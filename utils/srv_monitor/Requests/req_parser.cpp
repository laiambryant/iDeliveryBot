#include "req_parser.h"

int req_parser::get_req_no(string req){
    int beginning = req.find_first_of('[')+1;
    int end = req.find_first_of(',');
    int req_no = 0;
    const string no_str = req.substr(beginning, end-beginning);
    try{
        req_no = stoi(no_str);
    }catch (const std::invalid_argument & e) {
            std::cout << e.what() << "\n";
    }
    catch (const std::out_of_range & e) {
            std::cout << e.what() << "\n";
    }
    return req_no;
}
msg_type req_parser::get_msg_type(string req){
    int beginning = req.find_first_of(',')+1;
    int end = req.find_first_of(']');
    return cvt_string_toMsgType(req.substr(beginning, end-beginning));
}
string req_parser::get_msg_body(string req){
    int beginning = req.find_first_of(':')+1;
    return req.substr(beginning);
}

string req_parser::cvt_msg_type_toString(msg_type type){
    return _msg_type_string[type];
}

msg_type req_parser::cvt_string_toMsgType(const string type_string){    
    switch(s_mapMsgType[type_string]){
        case login:
            return login;
        case call:
            return call; 
        case priority_call:
            return priority_call;
        case arrived:
            return arrived;
        case obj_sent:
            return obj_sent;
        case obj_rcvd:
            return obj_rcvd;
        case cancel:
            return cancel;
        case timeout:
            return timeout;
        default:
            return invalid;
    }
}