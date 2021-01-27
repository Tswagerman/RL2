//#define XERR
#include "mazesolver.ih"

mazeSolver::~mazeSolver()
{
    cout << "MazeSolver Destroyed!" << endl;
    //delete[] m_QValue;
    delete[] d_maxCurrentQValue;
    //delete d_sarsa;
    delete[] d_averageMaxCurrentQValue;
}
