//#define XERR
#include "mazesolver.ih"

vector<cell> mazeSolver::setMazeQToZero(vector<cell> &mazeGrid)
{
    size_t sizeMaze = d_height*d_width;
    memset(m_QValue, 0, sizeof(float) * SIZE); 
    memset(d_sarsa, 0, sizeof(float) * SIZE); 
    
    for (size_t idx = 0; idx < sizeMaze; ++idx)
    {
        mazeGrid.at(idx).setQValue(m_QValue);
        mazeGrid.at(idx).setP(0);
    }
    return mazeGrid;
}
