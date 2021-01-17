//#define XERR
#include "mazesolver.ih"

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    //Reset to the starting node.    
    d_currentCell = mazeGrid.at(d_start);
    //Resetting all the learned Q values to 0.
    mazeGrid = setMazeQToZero(mazeGrid);
    for (d_steps = 0; (d_steps < 10); ++d_steps)
    {                
        //m_QValue is used to keep track of the current Q value        
        m_QValue = d_currentCell.getQValue();  
        cout << "\033[1;31mRUN\033[0m" << d_runs << "\033[1;31m| STEP :\033[0m" 
            << d_steps << endl;
        cout << "FIRST OF LOOP" << endl;        
        d_currentCell.print();
        m_V = valueFunc(mazeGrid, 0, 0.0, d_idxCell);
        d_currentCell.setV(m_V);
        cout << "AFTER VALUE FUNC" << endl;   
        d_currentCell.print();                 
        mazeGrid.at(d_idxCell) = d_currentCell;
        d_currentCell.print();
        //Creating a copy of the next cell
        cell nextCell(0, 0, ' ');
        for (size_t idx = 0; idx < SIZE; ++idx)
        {     
            d_action = action(idx);
            //Recursion to next cell
            nextCell = mazeGrid.at(d_idxCell + d_action);
            m_QValue[idx] = nextCell.getV();
        }     
        //UPDATE THE CURRENT CELL'S QVALUE AND MAZEGRID               
        d_currentCell.setQValue(m_QValue);    
        cout << "AFTER VALUE FUNC" << endl;   
        d_currentCell.print();                 
        mazeGrid.at(d_idxCell) = d_currentCell;
        d_currentCell.print();
        //Selecting direction
        d_actionSelection = selectAction(m_QValue);  
        //Corresponding change in position in accordance with direction   
        d_action = action(d_actionSelection);
        cout << "\033[1;34mACTIONSELECTION = \033[0m" << d_actionSelection << endl
            << "\033[1;34m| DIRECTION = \033[0m" << d_action << endl; 
 
        nextCell = mazeGrid.at(d_idxCell + d_action);
        cout << "\033[1;31mNEXTCELL = \033[0m" << endl;
        nextCell.print();  
        //Calculating the current maximum Q-value
        d_maxQ = getMaxQ(d_currentCell.getQValue());           
        //To visualize the max Q value over the run.        
        if (d_idxCell != d_start)
            d_maxCurrentQValue[d_steps] = d_maxCurrentQValue[d_steps - 1] + d_maxQ;
        else
            d_maxCurrentQValue[d_steps] = d_maxQ;
        //Checking whether the next cell is a border and 
        //whether the direct neighbors of currentCell have been explored completely
        if ((nextCell.getBorder() == false))               
        {     
            d_sAction.push(d_action);     
            d_sQValue.push(d_maxQ);   
            d_idxCell += d_action;
            d_currentCell = nextCell; 
        } 
        //FOUND THE EXIT
        if ((d_exit == true) & (nextCell.getExit() == true))
        {
            //Reset the current node to the starting node.
            reset(mazeGrid);
            ++d_countSolves;
        }
        //FOUND THE EXIT IN RECURSION
        if ((d_exit == true) & (nextCell.getExit() == false))
            d_exit = false;
        //RESET POSITION AT END OF LOOP        
        if (d_steps == (ACTIONSELECTIONS - 1))
            d_idxCell = d_start;
    }
    cout << "d_countSolves = " << d_countSolves << endl;
    d_countSolves = 0; 
}

/*
void print1(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < SIZE; i++) 
        input.at(i).print();
}
*/
