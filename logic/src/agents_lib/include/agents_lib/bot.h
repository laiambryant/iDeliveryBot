#pragma once
#include "../include/agents_lib/agent.h"
#include <vector>

//Status for the bot
typedef enum bot_status{
    IDLE, COLLECTING, DELIVERING,
    RETURNING, WAITING, ERROR, CANCELLING, DELIVERED
} bot_status;

using std::vector;
using coords = vector<float>;

class bot : public agent{
private:
    bot_status _status;
    vector<coords> _coords_list;
    int _coord_list_size = 0;
    float _theta;
    coords _curr_obj, _old_obj;
    coords _old_pos, _sender, _reciever;

public:
//CTORS--------------------------------------------------------------------------------------------------
    
    //Default ctor, sets bot pos to (49.435,11.796) theta(4.371e-08) and status to IDLE
    bot(): _status(IDLE), agent(49.43519973754883,11.796863555908203), _theta(4.371139000186241e-08){
        _curr_obj = this->get_pos(); _old_pos = this->get_pos(); _old_obj = this->get_pos();
        _sender = this->get_pos(); _reciever = this->get_pos();

    }; 
    //Sets pos to x,y and rot to theta, default status set is idle
    bot(float x, float y, float theta_): _status(IDLE), agent(x,y), _theta(theta_){};
    
//GETTERS------------------------------------------------------------------------------------------------
    
    bot_status get_status(){return this->_status;}
    coords get_curr_obj(){return this->_curr_obj;}
    coords get_old_obj(){return this->_old_obj;}
    coords get_old_pos(){return this->_old_pos;}
    coords get_sender(){return this->_sender;}
    coords get_reciever(){return this->_reciever;}
    
//SETTERS------------------------------------------------------------------------------------------------
    
    void set_old_pos(coords old){this->_old_pos = old;}
    void set_curr_obj(float x, float y){this->_curr_obj[0]=x;this->_curr_obj[1]=y;}
    void set_old_obj(float x, float y){this->_old_obj[0]=x; this->_old_obj[1]=y;}
    void set_sender(float x, float y){this->_sender[0]=x; this->_sender[1]=y;}
    void set_reciever(float x, float y){this->_reciever[0]=x; this->_reciever[1]=y;}
    void set_status(bot_status status){this->_status = status;};
    
//FUNCS--------------------------------------------------------------------------------------------------

    //Adds new objective to the objectives list and increments the 
    void add_objective(float x, float y);

    ~bot(){};
};

