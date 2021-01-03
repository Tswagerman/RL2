#ifndef INCLUDED_MAZE_
#define INCLUDED_MAZE_
#include "../cell/cell.h"

#include <cstddef>

class maze
{
    size_t d_width;
    size_t d_height;
    cell *d_mazeGrid; 
    public:
        Maze();
        Maze(size_t width, size_t height);
        ~Maze();
        void swap(maze &other);

    private:
        void initMaze();
};
        
#endif
