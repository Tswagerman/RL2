//#define XERR
#include "mazesolver.ih"

float mazeSolver::valueFunc(std::vector<cell> &mazeGrid, int step, float reward, size_t idxCell)
{   //Guard when out of bounds of the maze vector. 
    if (((idxCell) < 0) | ((idxCell) > (d_height * d_width)))
        return -5; //Returning the border reward. 
    if (step > 2) //to prevent recursion to go too deep, without much effect.
        return reward; 
    float currentReward, alpha = 0.1; 
    int direction = d_action;
    size_t idxPlusAction, actionSelection = d_actionSelection;
    cell nextCell(0, 0, ' ');
    nextCell = mazeGrid.at(idxCell);
    //cout << "STEPS = " << step << endl;
    
    //cout << "RECURSION CELL PRINT" << endl;
    //nextCell.print();
    //d_maxQ = getMaxQ(currentCell.getQValue());
    //Bellman Equation
    currentReward = nextCell.getReward();
    reward = pow(alpha, step) * currentReward;
    //if (currentCell.getBorder() == true)
    //    return reward;
    if (nextCell.getExit() == true)
    { 
        //Exit found
        d_exit = true;
        return reward;
    }
    for (size_t idx = 0; idx < (SIZE); ++idx)
    {
        actionSelection = idx;      
        direction = action(actionSelection);
        idxPlusAction = idxCell + direction;
        //Recursion to next cell
        //cout << "recursion!" << endl;
        reward += (valueFunc(mazeGrid, step + 1, reward, idxPlusAction)); 
    }
    cout << "REWARD = " << reward << endl;
    return reward;
}


