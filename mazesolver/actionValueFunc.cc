//#define XERR
#include "mazesolver.ih"

float mazeSolver::actionValueFunc(std::vector<cell> &mazeGrid, int step, float reward, size_t idxCell)
{   //Guard when out of bounds of the maze vector. 
    if (((idxCell) < 0) | ((idxCell) > (d_height * d_width)))
    {
        return -5; //Returning the border reward.
    }   
    if (step > 10) //to prevent recursion to go too deep, without much effect.
        return reward; 
    float discountRate = 0.4; 
    int direction = d_action;
    size_t actionSelection = d_actionSelection;
    size_t idxPlusAction;
    cell currentCell(0, 0, ' ');
    currentCell = mazeGrid.at(idxCell);
    d_maxQ = getMaxQ(currentCell.getQValue());
    //Bellman Equation
    reward += d_maxQ * pow(discountRate, step);
    if (currentCell.getBorder() == true)
        return reward;
    if (currentCell.getExit() == true)
    { 
        //Exit found
        d_exit = true;
        return reward;
    }
    actionSelection = selectAction(mazeGrid.at(idxCell).getQValue());      
    direction = action(actionSelection);
    idxPlusAction = idxCell + direction; 
    //if (d_maxQ == 0) // no Q value from here on, so no need for recursion
        //return reward;
    //Recursion to next cell
    return actionValueFunc(mazeGrid, step + 1, reward, idxPlusAction);
}


