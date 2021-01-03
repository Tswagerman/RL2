//#define XERR
#include "maze.ih"

void maze::initMaze()
{
    cell currentCell = getCell(col, row);
    for (size_t col = 0; col < d_width; ++col)
    {
        for (size_t row = 0; row < d_height; ++row)
        {
            d_mazeGrid[row * d_width + col] = cell(;
        }
    }
}
