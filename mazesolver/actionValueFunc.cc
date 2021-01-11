//#define XERR
#include "mazesolver.ih"

float mazeSolver::actionValueFunc(std::vector<cell> &mazeGrid, int step, float reward, size_t idxCell)
{ 
    //mazeGrid.at(d_idxCell).print();
    //cout << " ACTIONVALUEFUNC " << endl << "action = " << d_action 
    //    << "| idx = " << d_idxCell << endl;
    //cout << "recursion" << endl; 
    //cout << "idx = " << d_idxCell << endl;
    float discountRate = 0.9;
    int direction;
    size_t actionSelection;
    size_t idxPlusAction;
    if (step == 0)
        actionSelection = d_actionSelection;
    else        
        actionSelection = selectAction(); 
    direction = action(actionSelection); //first time goes wrong
    idxPlusAction = idxCell + direction;
    if (((idxPlusAction) >= 0) & ((idxPlusAction) < (d_height * d_width)))
    {
        cout << "INNER INDEX = " << idxPlusAction << endl;
        cell nextCell(0, 0, ' ');
        nextCell = mazeGrid.at(idxPlusAction); 
        reward += nextCell.getReward() * pow(discountRate, step);
        nextCell.print();
        if (nextCell.getBorder() == true)
        {
            cout << "WALL!!!" << endl;
            cout << "1: Reward = " << reward << endl;
            return reward;// reward ;//+ nextCell.getReward() * pow(discountRate, step);
        }      
        cout << "2: Reward = " << reward << endl;
        return reward + actionValueFunc(mazeGrid, step + 1, reward, idxPlusAction);        
    }
    else
        return reward -= 75;
}

