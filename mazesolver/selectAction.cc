//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::selectAction(float* QValue)
{

    size_t action = 0;
    float max = QValue[0];
    //cout << "RANDOM ACTION SELECTED: " << d_actionSelection << endl;
    for (size_t idx = 0; idx < SIZE; ++idx)
        if (QValue[idx] > max)
        {
            max = QValue[idx];
            action = idx;
        }
    return action;
}
