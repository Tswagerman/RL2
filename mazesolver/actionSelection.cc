//#define XERR
#include "mazesolver.ih"

int mazeSolver::actionSelection()
{   
    getMaxQValue(); 
    int action;
    //cout << "ACTION SELECTED: " << d_actionSelection << endl;
    switch(d_actionSelection)
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
    //cout << "actionSelected = " << actionSelected << " | action = " << action << endl;
    return action;
}

