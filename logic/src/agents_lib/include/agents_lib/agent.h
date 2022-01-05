#pragma once

class agent{
private:
    float pos_x;
    float pos_y;
public:
    agent();
    agent(float x, float y):pos_x(x),pos_y(y){};
    ~agent(){};
};
