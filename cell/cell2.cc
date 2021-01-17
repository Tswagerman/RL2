//#define XERR
#include "cell.ih"

cell::cell(size_t width, size_t height, char character)
  :d_x(width),
    d_y(height),
    d_character(character)
{
    //cout << "Cell Created!" << endl;
    //SIZE defined in cell.h
    d_QValue = new float[SIZE]; //Default q values for four directions
    d_V = 0;
    memset(d_QValue, 0, sizeof(float) * SIZE); //memset can be used to set array to 0   
    setStart(false);
    setBorder(false);
    setExit(false); 
    if ((getCharacter() == '_') | (getCharacter() == '|'))
    {
        setBorder(true);
        setReward(-5); //Walking into walls is punished    
    }
    else if (getCharacter() == 'S') //Starting point
    {
        setStart(true);
        setReward(-1.5);
    }    
    else if (getCharacter() == 'X')
    {
        setExit(true);
        setReward(100); //The exit of the maze
    }
    else if (getCharacter() == 'P')
        setReward(-1.5); //making sure unnecessary moves are punished
}
