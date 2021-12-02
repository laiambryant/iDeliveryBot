#include "../Requests/req.h"
#include "../Requests/req_parser.h"

#include <iostream>

int main(int argc, char const *argv[]){
    
    string login_str ="[0,LOGIN]:User:{username:Dsadsafdsf,password:fdafs}";
    req_parser parser;

    msg_type type = parser.get_msg_type(login_str);
    string body = parser.get_msg_body(login_str);
    int req_no = parser.get_req_no(login_str);
    
    req login_request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
    login_request.print_metadata(cout);

    return 0;
}
