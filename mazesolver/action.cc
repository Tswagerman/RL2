//#define XERR
#include "mazesolver.ih"

int mazeSolver::action(size_t actionSelection)
{    
    int action;
    //cout << "ACTION SELECTED: " << d_actionSelection << endl;
    switch(actionSelection)
    {
        case(0):
            action = -d_width; //North
            break;
        case(1):
            action = 1; //East
            break;
        case(2):
            action = d_width; //South
            break;
        case(3):
            action = -1; //West
            break;
    }
    //cout << "actionSelected = " << actionSelected << " | action = " << action << endl;
    return action;
}

