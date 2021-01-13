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
    mazeGrid.at(d_idxCell).print();
    cout << "loop" << endl;
    //ACTIONSELECTIONS defined in 'mazesolver.h'
    for (d_steps = 0; (d_steps < ACTIONSELECTIONS); ++d_steps)
    {        
        //cout << "\033[1;31mRUN: \033[0m" << d_runs <<          
        m_QValue = d_currentCell.getQValue();  
        d_actionSelection = selectAction(m_QValue);      
        d_action = action(d_actionSelection);  
        cell nextCell(0, 0, ' ');
        nextCell = mazeGrid.at(d_idxCell + d_action);       
        m_QValue[d_actionSelection] = nextCell.getReward() + actionValueFunc(mazeGrid, 1, 0.0, d_idxCell + d_action);               
        d_currentCell.setQValue(m_QValue);        
        //UPDATE MAZEGRID                      
        mazeGrid.at(d_idxCell) = d_currentCell;
        //Checking whether the next cell is a border and 
        //whether the direct neighbors of currentCell have been explored completely
        d_maxQ = getMaxQ(d_currentCell.getQValue());
        //to visualize the max Q value over the run.   
        if (d_idxCell != d_start)
            d_maxCurrentQValue[d_steps] = d_maxCurrentQValue[d_steps - 1] + d_maxQ;
        else
            d_maxCurrentQValue[d_steps] = d_maxQ;
        if ((nextCell.getBorder() == false) & (d_maxQ != 0))               
        {     
            d_sAction.push(d_action);     
            d_sQValue.push(d_maxQ);
                      
            d_idxCell += d_action;
            d_currentCell = nextCell; 
            
        } 
        if ((d_exit == true) & (nextCell.getExit() == true))
        {
            //FOUND THE EXIT
            //Reset the current node to the starting node.
            reset(mazeGrid);
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
        }*/ 
        //print1(mazeGrid, 12*11);
    }
    cout << "d_countSolves = " << d_countSolves << endl;
    //Reset to the starting node. DOES NOT RESET QVALUES TO 0
    //reset(mazeGrid);
    d_countSolves = 0; 
}
