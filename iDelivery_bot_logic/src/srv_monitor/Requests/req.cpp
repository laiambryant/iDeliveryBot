#include "req.h"

void req::print_metadata(ostream &stream){
    stream<<"-----------------------------------------"<<endl;
    stream<<"Request number:\t" << _req_no <<endl;
    stream<<"Request type:\t" << _req_type_str <<endl;
    stream<<"Body:\t\t"; _req_body_ptr->print(stream);
}