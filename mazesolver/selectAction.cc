//#define XERR
#include "mazesolver.ih"

size_t mazeSolver::selectAction(float* QValue)
{
    //Using Mersenne twister PRNG in order to initalize random seed.
    random_device rd;
    mt19937 gen(rd());
    double epsilon = 0.15;
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
	if ((epsilon >= p) & (d_countSolves < 100))
    {
        uniform_int_distribution<int> uniformDist(0, SIZE - 1); 
        int random = uniformDist(gen);
		return random;
	}/* NO E GREEDY IN RC FOR NOW*/

    /*if ((d_north == false) & (nextCell.getBorder() == false))
        d_north = true;
    if ((d_east == false) & (nextCell.getBorder() == false))
        d_east = true;
    if ((d_south == false) & (nextCell.getBorder() == false))
        d_south = true;
    if ((d_west == false) & (nextCell.getBorder() == false))
        d_north = false;
        d_east = false;
        d_south = false;
        d_west = true;*/
    return action;
}
    
