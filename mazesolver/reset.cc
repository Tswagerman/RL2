//#define XERR
#include "mazesolver.ih"

void PrintStack(stack<int> s)
{
    if (s.empty()) 
        return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

void PrintStack(stack<float> s)
{
    if (s.empty()) 
        return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

void mazeSolver::reset(std::vector<cell> &mazeGrid)
{    
    d_exit = false;
    d_idxCell = d_start;
    d_currentCell = mazeGrid.at(d_idxCell);
    float maxQ = 0;
    //cout << endl << "Action Stack" << endl;
    //PrintStack(d_sAction);
    //cout << endl << "QValue Stack" << endl;
    //PrintStack(d_sQValue);
    while (d_sAction.empty() != true) //both stacks are equally big
    {
        //cout << d_sAction.top() << ' ';                
        d_sAction.pop(); 
    }
    //cout << endl;
    while (d_sQValue.empty() != true) //both stacks are equally big
    {
        maxQ += d_sQValue.top();
        //cout << d_sQValue.top() << ' ';                
        d_sQValue.pop();    
    }
    
    //cout << "MAXQ VALUE = " << maxQ << endl;
}
