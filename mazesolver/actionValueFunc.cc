//#define XERR
#include "mazesolver.ih"

float mazeSolver::actionValueFunc(std::vector<cell> &mazeGrid, int step, float reward, size_t idxCell)
{     
    if (((idxCell) < 0) | ((idxCell) > (d_height * d_width)))
    {
        cout << "1: REWARD = " << reward << endl;
        return -10;
    }   
    if (step > 10)
        return reward; 
    float discountRate = 0.3;
    int direction = d_action;
    size_t actionSelection = d_actionSelection;
    size_t idxPlusAction;
    cell currentCell(0, 0, ' ');
    currentCell = mazeGrid.at(idxCell);
    //cout << "INNER CURRENT CELL = " << endl;
    //currentCell.print();
    d_maxQ = getMaxQ(currentCell.getQValue());
    //cout << "d_maxQ = " << d_maxQ << endl;
    reward += d_maxQ * pow(discountRate, step);
    cout << "step = " << step << "| INNER INDEX = " << idxCell << endl;
    if (currentCell.getBorder() == true)
    {
        cout << "\033[1;31mENCOUNTERED A WALL! \033[m" << endl;
        return reward;
    }
    if (currentCell.getExit() == true)
    { 
        cout << "\033[1;31mFOUND THE EXIT! \033[m" << endl;
        //reset to the starting node
        d_exit = true;
        return reward;
    }
    actionSelection = selectAction(mazeGrid.at(idxCell).getQValue());      
    direction = action(actionSelection);
    idxPlusAction = idxCell + direction; 
    cout << "direction = " << direction << "| idxPlusAction = " << idxPlusAction << endl;
    if (d_maxQ == 0) // no Q value
    {
        cout << "q = 0" << endl;
        return reward;
    }
    cout << "\033[1;31mRECURSION \033[m" << endl;
    return actionValueFunc(mazeGrid, step + 1, reward, idxPlusAction);
}


