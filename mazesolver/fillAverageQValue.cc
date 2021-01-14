//#define XERR
#include "mazesolver.ih"

void mazeSolver::fillAverageQValue(float* Qarray)
{
    for(int count = 0; count < ACTIONSELECTIONS; ++count)
    {
        d_averageMaxCurrentQValue[count] = (d_averageMaxCurrentQValue[count] * (d_runs) + Qarray[count])/ (d_runs + 1);//need to sum all q values 
    }
}
