#include "req.h"

void req::print_metadata(ostream &stream){
    stream<<"Request number:\t" << _req_no <<endl;
    stream<<"Request type:\t" << _req_type_str <<endl;
    stream<<"Request Body:\t" << _req_body <<endl;
}