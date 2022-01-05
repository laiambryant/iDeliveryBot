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
    float x_pos;
    float y_pos;

public:
    user():agent(0.0,0.0){};
    user(float x, float y):agent(x,y){};
    ~user();
};

