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
    if ((d_character == '_') | (d_character == '|'))
    {
        setBorder(true);
        setReward(-5); //Walking into walls is punished    
    }
    else if (d_character == 'S') //Starting point
    {
        setStart(true);
        setReward(-1.5);
    }    
    else if (d_character == 'T')
        setReward(-20); //Traps are present
    else if (d_character == 'G')
        setReward(1); //There is gold to be found too
    else if (d_character == 'X')
    {
        setExit(true);
        setReward(200); //The exit of the maze
    }
    else if (d_character == 'P')
        setReward(-1.5); //making sure unnecessary moves are punished
}
