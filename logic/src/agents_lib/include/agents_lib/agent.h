#pragma once
#include <vector>
//#include <iostream>

using std::vector;
using coords = vector<float>;


class agent{
private:
    float pos_x;
    float pos_y;
public:
//CTORS--------------------------------------------------------------------------------------------------

    //default ctor sets pos to (0,0)
    agent():pos_x(0.0), pos_y(0.0){};
    //sets pos to (x,y)
    agent(float x, float y):pos_x(x),pos_y(y){};

//GETTERS------------------------------------------------------------------------------------------------

    coords get_pos(){
        return {this->pos_x, this->pos_y};
    }
    
//SETTERS------------------------------------------------------------------------------------------------

    void update_pos(float x, float y);
    
    ~agent(){};
};
