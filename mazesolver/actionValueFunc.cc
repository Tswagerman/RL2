//#define XERR
#include "mazesolver.ih"

float mazeSolver::actionValueFunc(std::vector<cell> const &mazeGrid, int action, float discountRate, int step, float reward)
{
    
    d_idxCell += action;   
    cout << "action = " << action << endl << "idx = " << d_idxCell << endl;
    cout << "recursion" << endl;
    cell nextCell = mazeGrid.at(d_idxCell); 
    if (nextCell.getBorder() == true)
    {
        cout << "WALL!!!" << endl;
        return reward;// reward ;//+ nextCell.getReward() * pow(discountRate, step);
    }      
    reward += nextCell.getReward() * pow(discountRate, step);
    return actionValueFunc(mazeGrid, action, discountRate, step + 1, reward);
}
