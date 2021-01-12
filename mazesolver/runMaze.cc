//#define XERR
#include "mazesolver.ih"

void print1(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < SIZE; i++) 
    {
        input.at(i).print();
    }
}

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    d_currentCell = mazeGrid.at(d_start);
    cout << "loop" << endl;
    for (d_steps = 0; d_steps < 1000; ++d_steps)
    {        
        cout << "\033[1;31mRUN: \033[0m" << d_runs << 
            "\033[1;31m | Step: \033[0m" << d_steps << endl;           
        m_QValue = d_currentCell.getQValue();             
        d_actionSelection = selectAction(m_QValue);      
        d_action = action(d_actionSelection);  
        cell nextCell(0, 0, ' ');
        nextCell = mazeGrid.at(d_idxCell + d_action);       
        cout << "CURRENT CELL = " << endl;
        d_currentCell.print();
        m_QValue[d_actionSelection] = nextCell.getReward() + actionValueFunc(mazeGrid, 1, 0.0, d_idxCell + d_action);       
        d_currentCell.setQValue(m_QValue);  
        //cout << "after action value func CURRENT CELL = " << endl;
        //d_currentCell.print();           
        //UPDATE MAZEGRID                      
        mazeGrid.at(d_idxCell) = d_currentCell;
        //cout << "mazegrid cell updated = " << endl;
        mazeGrid.at(d_idxCell).print();
        if (d_exit == true)
        {
            d_exit = false;
            cout << "\033[1;31mRESET\033[m" << endl;
            d_idxCell = d_start;
            d_currentCell = mazeGrid.at(d_idxCell);
            while (d_sAction.empty() != true)
                d_sAction.pop();
            //break;
            ++d_countSolves;
        }
        d_sAction.push(d_action); 
        if ((nextCell.getBorder() == false) & (getMaxQ(d_currentCell.getQValue()) != 0))               
        {                  
                      
            d_idxCell += d_action;
            d_currentCell = nextCell; 
        } 
        else if ((nextCell.getBorder() == true) & (getMaxQ(d_currentCell.getQValue()) != 0))
        {
            cout << "\033[1;31mIF STatement\033[m" << endl;  
            d_action = d_sAction.top();
            d_idxCell -= d_action;
            d_sAction.pop();
            cell previousCell(0, 0, ' ');
            previousCell = mazeGrid.at(d_idxCell);
            d_currentCell = previousCell;
        } 
        //print1(mazeGrid, 12*11);
    }
   cout << "d_countSolves = " << d_countSolves << endl;
}
