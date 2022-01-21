#include "../include/agents_lib/utils.h"

float Id_SW_SqrtLinear(float x){
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating value
    i = 0x5f3759df - (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits back to float
    return x;
}