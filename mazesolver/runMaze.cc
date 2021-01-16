//#define XERR
#include "mazesolver.ih"

void print1(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < SIZE; i++) 
    {
        input.at(i).print();
    }
}

void mazeSolver::softMax()
{
//RC
    float sum = 0;
	for(size_t inc = 0; inc < SIZE; ++inc)
		sum += exp(m_QValue[inc]);

    for(size_t inc = 0; inc < SIZE; ++inc)
		m_QValue[inc] = (exp(m_QValue[inc])/sum);
	//printArray(d_Q, d_arms);
    //cout << "d_Q[d_armPicked] = " << d_armPicked << endl;
}

void mazeSolver::runMaze(vector<cell> &mazeGrid)
{
    d_currentCell = mazeGrid.at(d_start);
    
    mazeGrid = setMazeQToZero(mazeGrid);
    cout << "loop" << endl;
    mazeGrid.at(d_idxCell).print();
    float referenceReward = 0;
    float diff = 0;
    float alpha = 0.75;
    size_t count = 0;
    float currentReward = 0;
    //ACTIONSELECTIONS defined in 'mazesolver.h'
    for (d_steps = 0; (d_steps < ACTIONSELECTIONS); ++d_steps)
    {        
        m_QValue = d_currentCell.getQValue();
        softMax(); 
        //cout << "\033[1;31mDIFF = \033[0m" << diff << endl;
        //cout << "REFERENCE REWARD: " << referenceReward << endl; 
        //cout << "currentReward: " << currentReward << endl;
        //cout << "\033[1;31mAFTER M_QVALUE UPDATE \033[0m" << endl;
        //cout << "\033[1;31mAFTER SOFTMAX \033[0m" << endl;
        d_currentCell.setQValue(m_QValue);      
        //d_currentCell.print(); 
        //cout << "\033[1;31mFIRST OF LOOP \033[0m" << endl;        
        //cout << "\033[1;31mRUN: \033[0m" << d_runs <<    
        d_actionSelection = selectAction(m_QValue);      
        d_action = action(d_actionSelection);   
        cout << "direction = " << d_action << endl 
            << "actionSelection = " << d_actionSelection << endl;
        d_maxQ = m_QValue[d_actionSelection];
        cell nextCell(0, 0, ' ');
        nextCell = mazeGrid.at(d_idxCell + d_action); 
        nextCell.print();
        currentReward = nextCell.getReward();
        referenceReward = (referenceReward * (d_steps) + currentReward) / (d_steps + 1); 
        diff = (currentReward - referenceReward);
        m_QValue[d_actionSelection] += (alpha * diff);
        referenceReward += (alpha*diff);
        cout << "\033[1;31mDIFF = \033[0m" << diff << endl;
        cout << "REFERENCE REWARD: " << referenceReward << endl; 
        cout << "currentReward: " << currentReward << endl;
        //cout << "\033[1;31mAFTER M_QVALUE UPDATE \033[0m" << endl;
        d_currentCell.setQValue(m_QValue);      
        d_currentCell.print();      
        
          
        //m_QValue[d_actionSelection] += diff*0.4;        
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        //UPDATE MAZEGRID                      
        mazeGrid.at(d_idxCell) = d_currentCell;
        //Checking whether the next cell is a border and 
        //whether the direct neighbors of currentCell have been explored completely
        d_maxQ = getMaxQ(d_currentCell.getQValue());
        count += 1;
        //to visualize the max Q value over the run.   
        if (d_idxCell != d_start)
            d_maxCurrentQValue[d_steps] = d_maxCurrentQValue[d_steps - 1] + d_maxQ;
        else
            d_maxCurrentQValue[d_steps] = d_maxQ;
        if ((nextCell.getBorder() == false) & (count >= 3))               
        {     
            d_sAction.push(d_action);     
            d_sQValue.push(d_maxQ);   
            d_idxCell += d_action;
            d_currentCell = nextCell; 
            cout << "\033[1;31mTO NEXT CELL \033[0m" << endl;
            count = 0;
        } 
        if ((nextCell.getExit() == true))
        {
            //FOUND THE EXIT
            //Reset the current node to the starting node.
            reset(mazeGrid);
            ++d_countSolves;
        }
        if ((d_exit == true) & (nextCell.getExit() == false))
            d_exit = false;
        if (d_steps == (ACTIONSELECTIONS - 1))
            d_idxCell = d_start;
    }
    cout << "d_countSolves = " << d_countSolves << endl;
    //Reset to the starting node. DOES NOT RESET QVALUES TO 0
    d_countSolves = 0; 
}
/*
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
        if (d_steps == (ACTIONSELECTIONS - 1))
            d_idxCell = d_start;
*/
