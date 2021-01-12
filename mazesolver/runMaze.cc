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
    for (d_steps = 0; d_steps < 10000; ++d_steps)
    {        
        cout << "\033[1;31mRUN: \033[0m" << d_runs << 
            "\033[1;31m | Step: \033[0m" << d_steps << 
            "\033[1;31m | Solves: \033[0m" << d_countSolves << endl;           
        m_QValue = d_currentCell.getQValue();             
        d_actionSelection = selectAction(m_QValue);      
        d_action = action(d_actionSelection);  
        cell nextCell(0, 0, ' ');
        nextCell = mazeGrid.at(d_idxCell + d_action);       
        cout << "CURRENT CELL = " << endl;
        d_currentCell.print();
        m_QValue[d_actionSelection] = nextCell.getReward() + actionValueFunc(mazeGrid, 1, 0.0, d_idxCell + d_action);       
        d_currentCell.setQValue(m_QValue);        
        //UPDATE MAZEGRID                      
        mazeGrid.at(d_idxCell) = d_currentCell;
        //cout << "mazegrid cell updated = " << endl;
        cout << "action = " << d_action << "| idx = " << d_idxCell << endl;
        mazeGrid.at(d_idxCell).print();
        //Checking whether border and 
        //whether the direct neighbors of currentCell have been explored completely
        if ((nextCell.getBorder() == false) & (getMaxQ(d_currentCell.getQValue()) != 0))               
        {     
            d_sAction.push(d_action);                        
            d_idxCell += d_action;
            d_currentCell = nextCell; 
        } 
        if ((d_exit == true) & (nextCell.getExit() == true))
        {
            d_exit = false;
            cout << "\033[1;31mRESET\033[m" << endl;
            d_idxCell = d_start;
            d_currentCell = mazeGrid.at(d_idxCell);
            mazeGrid.at(d_idxCell).print();
            d_currentCell.print();
            while (d_sAction.empty() != true)
                d_sAction.pop();
            ++d_countSolves;
        }
        if ((d_exit == true) & (nextCell.getExit() == false))
            d_exit = false;
        
        
        /*else if ((nextCell.getBorder() == true) & (getMaxQ(d_currentCell.getQValue()) != 0) & (d_sAction.empty() == false))
        {  
            d_action = d_sAction.top();
            d_idxCell -= d_action;
            d_sAction.pop();
            cell previousCell(0, 0, ' ');
            previousCell = mazeGrid.at(d_idxCell);
            d_currentCell = previousCell;
        } */
        //print1(mazeGrid, 12*11);
    }
   cout << "d_countSolves = " << d_countSolves << endl;
}
