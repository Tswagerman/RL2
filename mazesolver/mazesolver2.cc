//#define XERR
#include "mazesolver.ih"

mazeSolver::mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start)
{
    d_currentCell = mazeGrid.at(start);
    //d_currentCell.print();
}
