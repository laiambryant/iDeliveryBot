#include "req.h"


void req::print_metadata(out_mode out){
 
    ofstream file; 
    switch (out){
    case log_out:
        file.open(LOG_PATH);  
        file<<"Request number:\t" << _req_no <<endl;
        file<<"Request type:\t" << _req_type_str <<endl;
        file<<"Request Body:\t" << _req_body <<endl;
        file.close();
        break;

    case cerr_out:    
        cerr<<"Request number:\t" << _req_no <<endl;
        cerr<<"Request type:\t" << _req_type_str <<endl;
        cerr<<"Request Body:\t" << _req_body <<endl; 
        break;
    
    case cout_out:
        cout<<"Request number:\t" << _req_no <<endl;
        cout<<"Request type:\t" << _req_type_str <<endl;
        cout<<"Request Body:\t" << _req_body <<endl; 
        break;
    }
}