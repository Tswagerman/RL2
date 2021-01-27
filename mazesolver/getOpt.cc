//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::getOpt(float* array) const
{
    //Using Mersenne twister PRNG in order to initalize random seed.
    random_device rd;
    mt19937 gen(rd());    
    uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
    int random = uniformDist(gen);    
    size_t action = random;
    float max = array[random];
    for (size_t idx = 0; idx < SIZE; ++idx)
        if (array[idx] > max)
        {
            max = array[idx];
            action = idx;
        }
    return action;
}

