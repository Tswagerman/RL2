//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::getOpt(float* array)
{
    size_t action = 0;
    float max = array[0];
    //cout << "RANDOM ACTION SELECTED: " << d_actionSelection << endl;
    for (size_t idx = 0; idx < SIZE; ++idx)
        if (array[idx] > max)
        {
            max = array[idx];
            action = idx;
        }
    return action;
}

