#include "../include/srv_monitor_lib/req.h"

void req::print_metadata(ostream &stream){
    stream<<"-----------------------------------------"<<endl;
    stream<<"Request number:\t" << _req_no <<endl;
    stream<<"Request type:\t" << _req_type_str <<endl;
    stream<<"Body:\t\t"; _req_body_ptr->print(stream);
}

void req::act(){
    cerr << _req_type << endl;
    switch (_req_type){
        case login:
            cerr << "Login handler" <<endl;
            break;
        case call:
            cerr << "Call handler" <<endl;
            break;            
        case priority_call:
            cerr << "P_Call handler" <<endl;
            break;
        case arrived:
            cerr << "Arrived handler" <<endl;
            break;
        case obj_sent:
            cerr << "Obj_sent handler" <<endl;
            break;
        case obj_rcvd:
            cerr << "Obj_rcvd handler" <<endl;
            break;
        case cancel:
            cerr << "Cancel handler" <<endl;
            break;
        case timeout:
            cerr << "Timeout handler" <<endl;
            break;
        default:
            cerr << "Default handler" <<endl;
            break;
    }
}
/*
void req::login_handler(){
    //Here in theory one could connect to a database to authenticate users
    //I'll just use a csv here to authenticate client as one of the users 
    //(each user has a position in the map)
    string username = get_body()->get_username();
    string password = get_body()->get_password();

    array <float,3> coords (csv_login(username, password));
    
    cerr << "[x]:"<< coords.at(0) << endl;
    cerr << "[y]:"<< coords.at(1) << endl;
    cerr << "[z]:"<< coords.at(2) << endl;
}
*/