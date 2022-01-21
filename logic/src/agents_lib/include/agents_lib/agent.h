#pragma once
#include <vector>

using std::vector;

class agent{
private:
    float pos_x;
    float pos_y;
public:
    agent();
    agent(float x, float y):pos_x(x),pos_y(y){};
    vector<float> get_pos(){return vector<float>(pos_x,pos_y);}
    void update_pos(float x, float y);
    ~agent(){};
};
