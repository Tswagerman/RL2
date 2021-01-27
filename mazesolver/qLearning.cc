//#define XERR
#include "mazesolver.ih"

void mazeSolver::qLearning()
{
    float alpha = 0.99; //0.99
    float p = 0.8;   //0.8
    m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + 
                alpha * ((d_nextCell.getReward()) + p * getMaxQ(d_nextCell.getQValue()) 
                - m_QValue[d_actionSelection]);
}
