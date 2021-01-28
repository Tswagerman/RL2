//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::selectAction(float* QValue)
{
    double epsilon = 0.1;
    switch(d_alg)
    {
        case 0://QLearning
            epsilon = 0.15 - (0.0001 * d_steps);
            break;
        case 1://rLearning
            epsilon = 0.5 - (0.001 * d_steps);
            break;
        case 2://Sarsa
            epsilon = 0.15 - (0.1 * d_steps);
            break; 
    }; 
    (epsilon > 0) ? epsilon = epsilon : epsilon = 0;
    double p = (double)rand()/(double)(RAND_MAX/1);
    size_t action = 0;
    action = getOpt(QValue);
    //Exploration. Only explore for the first few solutions.
	if ((epsilon >= p))
    {
        //Using Mersenne twister PRNG in order to initalize random seed.
        random_device rd;
        mt19937 gen(rd());        
        uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
        int random = uniformDist(gen);
		return random;
	}
    return action;
}

