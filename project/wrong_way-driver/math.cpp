
#include "math.hpp"
#include <ctime>

float GetRandom(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
    
}