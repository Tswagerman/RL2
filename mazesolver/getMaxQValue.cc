//#define XERR
#include "mazesolver.ih"

void mazeSolver::getMaxQValue()
{
    //Using Mersenne twister PRNG in order to initalize random seed.
    random_device rd;
    mt19937 gen(rd());
	//Randomize which action to take when all action values are equal
    uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
    int random = uniformDist(gen);
    float max = m_QValue[random];
    d_actionSelection = random;
    //cout << "RANDOM ACTION SELECTED: " << d_actionSelection << endl;
    for (size_t idx = 0; idx < SIZE; ++idx)
    {
        if (m_QValue[idx] > max)
            d_actionSelection = idx;
    } 
}
