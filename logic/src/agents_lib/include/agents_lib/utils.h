#include "math.h"

//Iconic inverse sqrt used by id software and created by Terje Mathisen and Gary Tarolli
// Mathematician Chris Lomont suggested substituting 0x5f3759df with 0x5f375a86, as
// explained here http://www.lomont.org/papers/2003/InvSqrt.pdf
float Id_SW_SqrtLinear(float x);