//#define XERR
#include "mazesolver.ih"

void mazeSolver::reset(std::vector<cell> &mazeGrid)
{    
    d_exit = false;
    d_idxCell = d_start;
    d_currentCell = mazeGrid.at(d_idxCell);
    float maxQ = 0;
    while (d_sAction.empty() != true) //both stacks are equally big
    {
        cout << d_sAction.top() << ' ';                
        d_sAction.pop(); 
    }
    cout << endl;
    while (d_sQValue.empty() != true) //both stacks are equally big
    {
        maxQ += d_sQValue.top();
        cout << d_sQValue.top() << ' ';                
        d_sQValue.pop();    
    }
    cout << endl << "MAXQ VALUE = " << maxQ << endl;
}
