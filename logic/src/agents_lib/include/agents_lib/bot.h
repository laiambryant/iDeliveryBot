#pragma once
#include "../include/agents_lib/agent.h"
#include <vector>

//Status for the bot
typedef enum bot_status{
    IDLE, COLLECTING, DELIVERING,
    RETURNING, WAITING, ERROR
} bot_status;

using std::vector;
using coords = vector<float>;

class bot : public agent{
private:
    bot_status _status;
    vector<coords> _coords_list;
    int _coord_list_size = 0;
    float _theta;
    coords _curr_obj;
    coords _old_pos;

public:
//CTORS--------------------------------------------------------------------------------------------------
    
    //Default ctor, sets bot pos to (49.435,11.796) theta(4.371e-08) and status to IDLE
    bot(): _status(IDLE), agent(49.43519973754883,11.796863555908203), _theta(4.371139000186241e-08){
        _curr_obj = this->get_pos(); _old_pos = this->get_pos();
    }; 
    //Sets pos to x,y and rot to theta, default status set is idle
    bot(float x, float y, float theta_): _status(IDLE), agent(x,y), _theta(theta_){};
    
//GETTERS------------------------------------------------------------------------------------------------
    
    bot_status get_status(){return _status;}
    coords get_curr_obj(){return _curr_obj;}
    coords get_old_pos(){return _old_pos;}
    
//SETTERS------------------------------------------------------------------------------------------------
    
    void set_old_pos(coords old){_old_pos = old;}
    void set_curr_obj(float x, float y){_curr_obj[0]=x;_curr_obj[1]=y;}
    void set_status(bot_status status){this->_status = status;};
    
//FUNCS--------------------------------------------------------------------------------------------------

    //Adds new objective to the objectives list and increments the 
    void add_objective(float x, float y);

    ~bot(){};
};

