//#define XERR
#include "mazesolver.ih"

void print1(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        input.at(i).print();
    }
}

void print1(float* input)
{
    for (size_t i = 0; i < SIZE; i++) {
        cout << "m_QValue = " << input[i] << endl;
    }
}

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    for (d_runs = 0; d_runs < 1; ++d_runs)
    {
        //DEFAULT TO STARTING GRID
        //Don't forget to actually set the QValue of all cells in mazeGrid to 0!
        d_currentCell = mazeGrid.at(d_start);
        cout << "##################LOOP##################" << endl;
        //d_currentCell.print();
               
        for (d_steps = 0; d_steps < 1000; ++d_steps)
        {
            cout << "RUN: " << d_runs << "| STEP : " << d_steps << endl;            
            d_currentCell.print();            
            m_QValue = d_currentCell.getQValue();    
            print1(m_QValue);  
            d_actionSelection = selectAction();      
            d_action = action(d_actionSelection);
            //recursive function that estimates the reward. 
            cout << "ACTION SELECTED: " << d_actionSelection << endl;
            cout << "1 - runMaze : idx = " << d_idxCell << "| action = " << d_action << endl;  
            m_QValue[d_actionSelection] = actionValueFunc(mazeGrid, 0, 0.0, d_idxCell);      
            print1(m_QValue);            
            cout << "2 - runMaze : idx = " << d_idxCell << "| action = " << d_action << endl;    
            d_currentCell.setQValue(m_QValue);  
            //selectAction(); 
            cell nextCell(0, 0, ' ');
            nextCell = mazeGrid.at(d_idxCell + d_action);  
            if (((d_idxCell + d_action) >= 0) & ((d_idxCell + d_action) < (d_height * d_width)))
            {              
                //To make sure that the mazegrid cells are updated after changing.
                //mazeGrid.at(d_idxCell - d_action) = d_currentCell;
                mazeGrid.at(d_idxCell) = d_currentCell;
                if (nextCell.getBorder() == false)                
                    d_currentCell = nextCell; 
            }     
            mazeGrid.at(d_idxCell).print();   
            cout << "\033[1;31mbold red text\033[0m\n";
        }
    }
}
