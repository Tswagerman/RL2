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
    setExit(false); 
    d_count = 0; //if implement, change swap, move and copy
    d_averageReward = 0;
    if ((d_character == '_') | (d_character == '|'))
    {
        setBorder(true);
        d_reward = -0.6; //Walking into walls is punished    
    }
    else if (d_character == 'S') //Starting point
    {
        setStart(true);
        d_reward =  -0.5;
    }    
    else if (d_character == 'T')
        d_reward = -1; //Traps are present
    else if (d_character == 'G')
        d_reward = 1; //There is gold to be found too
    else if (d_character == 'X')
    {
        setExit(true);
        d_reward = 5; //The exit of the maze
    }
    else if (d_character == 'P')
        d_reward = -0.5; //making sure unnecessary moves are punished
}
