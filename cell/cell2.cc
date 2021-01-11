//#define XERR
#include "cell.ih"

cell::cell(size_t width, size_t height, char character)
  :d_x(width),
    d_y(height),
    d_character(character)
{
    //cout << "Cell Created!" << endl;
    d_QValue = new float[SIZE]; //Default q values for four directions
    memset(d_QValue, 0, sizeof(float) * SIZE); //memset can be used to set array to 0
    setStart(false);
    setBorder(false);
    d_count = 0;
    d_averageReward = 0;
    if ((character == '_') | (character == '|'))
    {
        setBorder(true);
        d_reward = -50; //Walking into walls is punished    
    }
    else if (character == 'S') //Starting point
    {
        d_reward = 0;
        setStart(true);
    }    
    else if (character == 'T')
        d_reward = -200; //Traps are present
    else if (character == 'G')
        d_reward = 15; //There is gold to be found too
    else if (character == 'X')
        d_reward = 5000; //The exit of the maze
    else if (character == 'P')
        d_reward = -1; //making sure unnecessary moves are punished
}
