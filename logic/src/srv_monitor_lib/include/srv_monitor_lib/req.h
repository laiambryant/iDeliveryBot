#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>

#include "req_parser.h"
#include "body_types.h"

using namespace std;

class req{
private:
    int _req_no;
    generic_body  *_req_body_ptr; //pointer for late binding
    msg_type _req_type;
    string _req_type_str;
    void login_handler();
    void obj_sent_handler();
    void obj_rcv_handler();
    void cancel_handler();
    void timeout_handler();
    void call_handler();
    void p_call_handler();
    void arrived_handler();
    void default_handler();

public:
    req(int req_no_, string req_body_, msg_type req_type_, string req_type_str_):_req_no(req_no_),_req_type_str(req_type_str_) {       
        if (req_type_ == obj_sent           || 
            req_type_ ==obj_rcvd            || 
            req_type_ ==cancel              || 
            req_type_ ==timeout             )    
                _req_body_ptr = new r_id_body(req_body_);

        else if(req_type_ == login          ) 
                _req_body_ptr = new login_body(req_body_);

        else if(req_type_ == call           ||
                req_type_ == priority_call  ||
                req_type_ == arrived        )
                    _req_body_ptr = new coord_body(req_body_);

        else _req_body_ptr = new invalid_body(req_body_);
    }
    ~req(){
        free(_req_body_ptr);
    }
    void act();
    void print_metadata(ostream &stream);
    generic_body* get_body(){return _req_body_ptr;}
};

