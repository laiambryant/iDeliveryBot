#include "../include/agents_lib/bot.h"

void bot::add_objective(float x, float y){

    coords tmp = vector<float>(2);
    tmp[0] = x; tmp[1] = y;
    _coords_list.resize(_coord_list_size+1);
    _coords_list[_coord_list_size] = tmp;
    _coord_list_size++;
}

