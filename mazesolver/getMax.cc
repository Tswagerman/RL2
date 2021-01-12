//#define XERR
#include "mazesolver.ih"

float mazeSolver::getMaxQ(float* input) const
{
    float maxQ = input[0];
    for (int idx = 0; idx < SIZE; ++idx)
        if (input[idx] > maxQ)
            maxQ = input[idx]; 
    return maxQ;
}
