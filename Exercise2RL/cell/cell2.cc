//#define XERR
#include "cell.ih"

cell::cell(size_t width, size_t height, char character)
  :d_x(width),
    d_y(height)
{
    setStart(false);
    setBorder(false);
    if ((character == '_') | (character == '|'))
    {
        setBorder(true);
        d_reward = -5; //Walking into walls is punished    
    }
    else if (character == 'S') //Starting point
    {
        d_reward = 0;
        setStart(true);
        setBorder(true);
    }    
    else if (character == 'T')
        d_reward = -10; //Traps are placed inside the maze
    else if (character == 'G')
        d_reward = 15; //There is gold to be found too
    else if (character == 'X')
        d_reward = 25; //The exit of the maze
    else
        d_reward = -1; //making sure unnecessary movements are punished
}
