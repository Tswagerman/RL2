//#define XERR
#include "maze.ih"

maze::Maze(size_t width, size_t height)
    :d_width(width),
    d_height(height),
    d_mazeGrid(new cell[width * height])
{
    bool border;
    for (size_t col = 0; col < width; ++col)
    {
        for (size_t row = 0; row < height; ++row)
        {
            if (col == 0 || col == (width - 1) 
                || row == 0 || row == (height - 1))
            {
                border = true;
            } 
            else 
                border = false;
        }
    }
    initMaze();
}
