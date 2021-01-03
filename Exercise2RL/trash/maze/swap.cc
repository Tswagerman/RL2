//#define XERR
#include "maze.ih"

void maze::swap(maze &other)
{
    char buffer[sizeof(maze)];
    memcpy(buffer, this,   sizeof(maze));
    memcpy(static_cast<void *>(this),   &other, sizeof(maze));
    memcpy(static_cast<void *>(&other), buffer, sizeof(maze));
}
