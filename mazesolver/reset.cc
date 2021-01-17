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
    //float maxQ = 0;
    //while (d_sAction.empty() != true) both stacks are equal in size          
         
    //while (d_sQValue.empty() != true) //both stacks are equal in size  
    //{
    //    d_sAction.pop();        
        //maxQ += d_sQValue.top();             
    //    d_sQValue.pop();    
    //}
    //cout << "MAXQ VALUE = " << maxQ << endl;
}
