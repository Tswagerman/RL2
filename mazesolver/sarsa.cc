//#define XERR
#include "mazesolver.ih"

void mazeSolver::sarsa()
{
    d_sarsa = d_nextCell.getQValue();
    size_t actionSelection = selectAction(d_sarsa);  
    //Corresponding change in position in accordance with direction   
    float Qnext = d_sarsa[actionSelection];
    float alpha = 0.99; //0.95
    float discountRate = 0.78; //0.65
    float predict = m_QValue[d_actionSelection];
    float target = d_nextCell.getReward() + discountRate * Qnext;
    m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + alpha * (target - predict);
}
