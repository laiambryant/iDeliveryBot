#include "Monitor_thread.h"

void Monitor_thread::monitor_act(){

    int seconds = 0;
    while(seconds>20){
        string login_str = _monitor.get_last_msg();
    do {
        msg_type type = _parser.get_msg_type(login_str);
        string body = _parser.get_msg_body(login_str);
        int req_no = _parser.get_req_no(login_str);

        //late binding for body
        req login_request = req(req_no, body, type,_parser.cvt_msg_type_toString(type));
        login_request.print_metadata(cerr);
        login_str = _monitor.get_last_msg();
        
    } while (login_str!="");

    sleep(5);
    seconds += 5;

    }

}

void Monitor_thread::start(){
    thread _monitor_t = thread(monitor_act);
    _monitor_t.join();
}
