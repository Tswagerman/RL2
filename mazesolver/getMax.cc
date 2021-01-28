//#define XERR
#include "mazesolver.ih"

float mazeSolver::getMaxQ(float* input) const
{
    //Using Mersenne twister PRNG in order to initalize random seed.
    random_device rd;
    mt19937 gen(rd());        
    uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
    int random = uniformDist(gen);
    float maxQ = input[random];
    for (int idx = 0; idx < SIZE; ++idx)
        if (input[idx] > maxQ)
            maxQ = input[idx]; 
    return maxQ;
}
