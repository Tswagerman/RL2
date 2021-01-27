//#define XERR
#include "mazesolver.ih"

void mazeSolver::sarsa()
{
    d_sarsa = d_nextCell.getQValue();
    size_t actionSelection = selectAction(d_sarsa);  
    //Corresponding change in position in accordance with direction   
    float Qnext = d_sarsa[actionSelection];
    float alpha = 0.15;
    float discountRate = 0.9;
    m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + 
        alpha * ((d_nextCell.getReward()) + pow(discountRate, d_stepEpoch) * 
            Qnext - m_QValue[d_actionSelection]);
}
