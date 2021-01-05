//#define XERR
#include "mazesolver.ih"

mazeSolver::mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start)
  : d_height(heightMaze),
    d_width(widthMaze),
    d_idxCell(start)
{
    d_currentCell = mazeGrid.at(d_idxCell);
    d_x = d_currentCell.getWidth();
    d_y = d_currentCell.getHeight();
    d_QValue = new float[SIZE]; //SIZE defined in cell.h
    d_runs = 10;
    d_steps = 50;
    runMaze(mazeGrid);
    //d_currentCell.print();
}
