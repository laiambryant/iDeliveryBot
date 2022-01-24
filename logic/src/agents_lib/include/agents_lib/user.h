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
//CTORS--------------------------------------------------------------------------------------------------
    
    //Default ctor, sets default pos to 0 and status to USER_IDLE
    user():agent(0.0,0.0), _status(USER_IDLE){};
    //Sets pos to (x,y) and status to default USER_STATUS
    user(float x, float y):agent(x,y), _status(USER_IDLE){};

//GETTERS------------------------------------------------------------------------------------------------
    
    user_status get_status(){return _status;};

//SETTERS------------------------------------------------------------------------------------------------

    void set_status(user_status status_){_status=status_;}
    
//FUNCS--------------------------------------------------------------------------------------------------


    ~user();
};

