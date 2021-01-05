//#define XERR
#include "mazesolver.ih"

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    for (size_t run = 0; run < d_runs; ++run)
    {
        d_QValue = d_currentCell.getQValue();
        for (size_t step = 0; step < d_steps; ++step)
        {
            d_action = 0; //actionSelection();
            //d_QValue[d_action] = actionValueFunc(); //recursive function that
                                                        //estimates the reward.
            d_currentCell = mazeGrid.at(d_idxCell + d_action);
        }
    }
}

