#include "req.h"
#include "req_parser.h"
#include <iostream>

int main(int argc, char const *argv[]){
    
    string str ="[0, LOGIN]:User:{ username:Dsadsafdsf, password:fdafs}";
    req_parser parser;

    msg_type type = parser.get_msg_type(str);
    string body = parser.get_msg_body(str);
    int req_no = parser.get_req_no(str);
    
    req request = req(req_no, body, type, parser.cvt_msg_type_toString(type));
    request.print_metadata(cerr_out);

    return 0;
}
