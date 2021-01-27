//#define XERR
#include "mazesolver.ih"

void mazeSolver::reset(std::vector<cell> &mazeGrid)
{    
    d_exit = false;
    d_idxCell = d_start;
    d_currentCell = mazeGrid.at(d_idxCell);
    d_p = 0.9;
    d_Alpha = 0.5;
    d_Beta = 0.65;
    d_stepEpoch = 0;
}
