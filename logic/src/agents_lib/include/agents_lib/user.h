#pragma once
#include "../include/agents_lib/agent.h"

//WF stands for Waiting For
typedef enum user_status{
    USER_IDLE, 
    WF_COLLECTION, 
    WF_DELIVERY,
    WF_CONF_COLL, 
    WF_CONF_DEL
}user_status;

class user:public agent{
private:
    user_status _status;
public:
    user():agent(0.0,0.0), _status(USER_IDLE){};
    user(float x, float y):agent(x,y), _status(USER_IDLE){};
    user_status get_status(){return _status;};
    ~user();
};

