#pragma once
#include "../include/agents_lib/agent.h"
#include <vector>

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
    bot(): _status(IDLE), agent(49.43519973754883,11.796863555908203), _theta(4.371139000186241e-08){}; 
    bot(float x, float y, float theta_): _status(IDLE), agent(x,y), _theta(theta_){};
    void add_objective(float x, float y);
    
    bot_status get_status(){return _status;}
    coords get_curr_obj(){return _curr_obj;}
    coords get_old_pos(){return _old_pos;}
    
    void set_old_pos(coords old){_old_pos = old;}
    void set_curr_obj(float x, float y){_curr_obj = vector<float>(x,y);}
    void set_status(bot_status status){this->_status = status;};
    ~bot(){};
};

