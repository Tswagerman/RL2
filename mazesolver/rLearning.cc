//#define XERR
#include "mazesolver.ih"

void mazeSolver::rLearning()
{    
    m_QValue[d_actionSelection] = m_QValue[d_actionSelection] + 
                d_Alpha * (d_nextCell.getReward() - d_p + getMaxQ(d_nextCell.getQValue()) 
                - m_QValue[d_actionSelection]);
    if (d_actionSelection == getOpt(m_QValue))
    {      
        d_p = d_p + d_Beta * (d_nextCell.getReward() - d_p + getMaxQ(d_nextCell.getQValue()) 
            - getMaxQ(m_QValue));
    }
}
