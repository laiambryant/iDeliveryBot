#pragma once
#include "../include/agents_lib/agent.h"
#include <vector>

typedef enum bot_status{
    IDLE, COLLECTING, DELIVERING,
    RETURNING, WAITING, ERROR
} bot_status;

using std::vector;
using coords = vector<float> ;

class bot : public agent{
private:
    bot_status status;
    float x_pos;
    float y_pos;
    vector<coords> coords_list;

public:
    bot(): status(IDLE), agent(0.0,0.0){};
    bot(float x, float y): status(IDLE), agent(x,y){};
    void add_objective(float x, float y);
    bot_status get_status();
    ~bot(){};
};
