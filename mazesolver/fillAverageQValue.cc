//#define XERR
#include "mazesolver.ih"

void mazeSolver::fillAverageQValue(float* Qarray)
{   //need to sum all q values of all the runs and divide this to get the average
    for(int count = 0; count < ACTIONSELECTIONS; ++count)
    {
        d_averageMaxCurrentQValue[count] = (d_averageMaxCurrentQValue[count] *
             (d_runs) + Qarray[count])/ (d_runs + 1);
    }
}
