//#define XERR
#include "mazesolver.ih"

void print1(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        input.at(i).print();
    }
}

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    for (size_t run = 0; run < d_runs; ++run)
    {
        m_QValue = d_currentCell.getQValue();
        //d_currentCell.print();
               
        for (size_t step = 0; step < 10; ++step)
        {
            float discountRate = 0.9;
            int action = actionSelection();
            //recursive function that estimates the reward. 
            m_QValue[d_actionSelection] = actionValueFunc(mazeGrid, action, discountRate, 0, 0.0); 
            cout << "Out of recursion" << endl;            
            d_currentCell.setQValue(m_QValue);  
            getMaxQValue(); 
            cell nextCell = mazeGrid.at(d_idxCell);  
            d_currentCell.print();  
            //To make sure that the mazegrid cells are updated after changing.
            mazeGrid.at(d_idxCell - action) = d_currentCell;
            d_currentCell = nextCell;                    
            //d_currentCell.print();
        }
    }
}
