#pragma once
#include <iostream>
#include <fstream>
#include <memory>

#include "req_parser.h"
#include "Body/body_types.h"
using namespace std;

class req{
private:
    int _req_no;
    generic_body  *_req_body_ptr; //is pointer for late binding
    msg_type _req_type;
    string _req_type_str;

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

    void print_metadata(ostream &stream);
};

