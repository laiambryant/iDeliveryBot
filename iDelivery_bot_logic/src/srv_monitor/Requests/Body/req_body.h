#pragma once

#include <iostream>
#include <map>

#include "body_types.h"

/*
    Won't have a fully fledged json parser, will only handle the specific body
    type corresponding to a specific request type.
    For example, should server recieve 
    [0,LOGIN]:User:{username:aUsername,password:aPassword}
    the parser will check what type of request arrived (LOGIN in this case) and it will
    then know that the structure of the request is the following:
    
                        -------------------------   
                        |    User:{             |
                        |        username:""    |
                        |        password:""    |
                        |    }                  |
                        -------------------------
*/

using namespace std;

class req_body{
private:
    string _body_string;
    generic_body _body_formatted;
    void map_init();

public:
    req_body(string body_):_body_string(body_), _body_formatted(body_){map_init();}
    ~req_body();
};
