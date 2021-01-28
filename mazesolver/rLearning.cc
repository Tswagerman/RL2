//#define XERR
#include "mazesolver.ih"

void mazeSolver::rLearning()
{    
    m_p = 0;   
    //cout << "P = " << d_currentCell.getP() << endl;
    //d_currentCell.print();
    float alpha = 0.07; //0.07 p = 0.0015
    float beta = 0.001; //0.0001
    float target = d_nextCell.getReward() - d_currentCell.getP() + getMaxQ(d_nextCell.getQValue());
    float predict = m_QValue[d_actionSelection];
    m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + alpha * (target - predict);
    
    if (m_QValue[d_actionSelection] == getMaxQ(m_QValue))  
    {
        m_p = d_currentCell.getP() + beta * (target - getMaxQ(m_QValue));
        d_currentCell.setP(m_p);
    }    
}
