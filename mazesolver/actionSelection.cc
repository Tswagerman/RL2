//#define XERR
#include "mazesolver.ih"

int mazeSolver::actionSelection()
{
    int action;
    float max = d_QValue[0];
    size_t idx;
    for (idx = 0; idx < SIZE; ++idx)
    {
        if (d_QValue[idx] > max)
            max = d_QValue[idx];
    }
    switch(idx)
    {
        case(0):
            action = -d_height; //North
            break;
        case(1):
            action = 1; //East
            break;
        case(2):
            action = d_height; //South
            break;
        case(3):
            action = -1; //West
            break;
    }
    return action;
}

