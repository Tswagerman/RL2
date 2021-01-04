//#define XERR
#include "cell.ih"

cell::cell(size_t width, size_t height, char character)
  :d_x(width),
    d_y(height)
{
    //cout << "Cell Created!" << endl;
    d_QValue = new float[4]; //Default q values for four directions
    for(size_t inc = 0; inc < 4; ++inc)
    {
        d_QValue[4] = { 0 };
        //cout << "Q value 0 = " << d_QValue[0] << endl;
    }    
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
        d_reward = -20; //Traps are present
    else if (character == 'G')
        d_reward = 15; //There is gold to be found too
    else if (character == 'X')
        d_reward = 50; //The exit of the maze
    else
        d_reward = -1; //making sure unnecessary moves are punished
}
