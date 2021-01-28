//#define XERR
#include "mazesolver.ih"

/*void mazeSolver::doubleQlearning()
{    
    float alpha = 0.6, discountRate = 0.9, a = 0, b = 0;
    //m_QValue is used to keep track of the current Q value        
    m_QValueB = d_currentCell.getQValueB();  
    //Selecting direction
    size_t actionSelectionB = selectAction(m_QValueB);  
    //Corresponding change in position in accordance with direction   
    int directionB = action(d_actionSelection);
    if (m_QValueB[actionSelectionB] > m_QValue[d_actionSelection])
    {
        d_action = directionB;
        d_actionSelection = actionSelectionB;   
    }
    d_nextCell = mazeGrid.at(d_idxCell + d_action);
    random_device rd;
    mt19937 gen(rd());        
    uniform_int_distribution<int> uniformDist(0, 1); 
    int random = uniformDist(gen);  
    if (random == 0)
    {
        a = getOpt(m_QValue);  
        m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + alpha * (d_nextCell.getReward()
            + discountRate * d_nextCell.getQValueB[a] - m_QValue[d_actionSelection]); 
    }    
    else 
    {
        b = getOpt(m_QValueB); 
        m_QValueB[d_actionSelection] = m_QValueB[d_actionSelection] + alpha *
             (d_nextCell.getReward() + discountRate * d_nextCell.getQValue[b] -
             m_QValueB[d_actionSelection];
    }                             
}*/
