/*//#define XERR
#include "mazeSolver.ih"

void mazeSolver::softMax()
{
    float sum = 0;
	for(size_t inc = 0; inc < d_arms; ++inc)
		sum += exp(d_P[inc]);
    //cout << "sum = " << sum << endl;
    for(size_t inc = 0; inc < d_arms; ++inc)
		d_Q[inc] = (exp(d_P[inc])/sum);
	//printArray(d_Q, d_arms);
    //cout << "d_Q[d_armPicked] = " << d_armPicked << endl;
}

size_t mazeSolver::RC(float* QValue)
{         
    d_actionSelection = selectAction(QValue);      
    d_action = action(d_actionSelection); 
    d_maxQ = QValue[actionSelection];
    d_MaxQArm = highestValue;
    cell nextCell(0, 0, ' ');
    nextCell = mazeGrid.at(d_idxCell + d_action); 
    m_QValue[d_actionSelection] = nextCell.getReward() + actionValueFunc(mazeGrid, 1, 0.0, d_idxCell + d_action);
    float currentReward = m_QValue[d_actionSelection];
    float referenceReward = d_averageRewardRun;
    float diff = (currentReward - referenceReward);
    float alpha = 0.035;
    d_P[highestValue] += diff;
    d_averageRewardRun += alpha * diff;
    softMax();
    return highestValue;
}*/
