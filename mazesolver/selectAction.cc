//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::selectAction(float* QValue)
{
    //Using Mersenne twister PRNG in order to initalize random seed.
    random_device rd;
    mt19937 gen(rd());
    double epsilon = 0.015;
    double p = (double)rand()/(double)(RAND_MAX/1);
    size_t action = 0;
    float max = QValue[0];
    //cout << "RANDOM ACTION SELECTED: " << d_actionSelection << endl;
    for (size_t idx = 0; idx < SIZE; ++idx)
        if (QValue[idx] > max)
        {
            max = QValue[idx];
            action = idx;
        }
    //Exploration. Only explore for the first few solutions.
	if ((epsilon >= p) & (d_countSolves < 0))
    {
        uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
        int random = uniformDist(gen);
		return random;
	}
    return action;
}
    
