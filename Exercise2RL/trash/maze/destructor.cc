//#define XERR
#include "maze.ih"

maze::~Maze()
{
    cout << "Destroyed!" << endl;
    delete[] d_mazeGrid;
}
