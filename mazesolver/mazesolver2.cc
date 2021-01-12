//#define XERR
#include "mazesolver.ih"

mazeSolver::mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start)
  : d_height(heightMaze),
    d_width(widthMaze),
    d_idxCell(start),
    d_start(start)
{
    d_currentCell = mazeGrid.at(d_idxCell);
    d_x = d_currentCell.getWidth();
    d_y = d_currentCell.getHeight();
    m_QValue = new float[SIZE]; //SIZE defined in cell.h
    d_runs = 10;
    d_steps = 50;
    d_exit = false;
    d_countSolves = 0;
    //d_currentCell.print();
    cout << "BEFORE RUNMAZE#######" << endl << "idx = " << d_idxCell << endl;
    d_runs = 0;
    for (d_runs = 0; d_runs < 10; ++d_runs)
    {
        runMaze(mazeGrid);
    }
}
