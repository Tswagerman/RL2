//#define XERR
#include "mazesolver.ih"

void mazeSolver::reset(std::vector<cell> &mazeGrid)
{    
    d_exit = false;
    d_idxCell = d_start;
    d_currentCell = mazeGrid.at(d_idxCell);
    d_p = 0.06;
    d_Alpha = 0.75;
    d_Beta = 0.15;
    d_stepEpoch = 0;
}
