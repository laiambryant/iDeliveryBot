#include "../srv_monitor.h"

using namespace std;

int main(int argc, char const *argv[]){
  
    string login_str ="[0,LOGIN]:User:{username:adamkadmon,password:illuminati}";
    req_parser parser;

    msg_type type = parser.get_msg_type(login_str);
    string body = parser.get_msg_body(login_str);
    int req_no = parser.get_req_no(login_str);
    
    req login_request = req(req_no, body, type, parser.cvt_msg_type_toString(type));        
    
    string username = login_request.get_body()->get_username();
    string password = login_request.get_body()->get_password();

    array <float,3> coords (csv_login(username, password));
    
    cerr << "[x]:"<< coords.at(0) << endl;
    cerr << "[y]:"<< coords.at(1) << endl;
    cerr << "[z]:"<< coords.at(2) << endl;

    return 0;
}

