//#define XERR
#include "mazesolver.ih"

void print(float* Qarray);

mazeSolver::mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start)
  : d_height(heightMaze),
    d_width(widthMaze),
    d_idxCell(start),
    d_start(start)
{
    d_currentCell = mazeGrid.at(d_idxCell);
    d_nextCell = mazeGrid.at(d_idxCell); //Doesn't matter what its initialized as at first
    d_x = d_currentCell.getWidth();
    d_y = d_currentCell.getHeight();
    m_QValue = new float[SIZE]; //SIZE defined in cell.h
    d_sarsa = new float[SIZE];
    //ACTIONSELECTIONS defined in 'mazesolver.h'
    d_maxCurrentQValue = new float[ACTIONSELECTIONS]; 
    d_averageMaxCurrentQValue = new float[ACTIONSELECTIONS];
    //memset can be used to set array to 0    
    memset(d_maxCurrentQValue, 0, sizeof(float) * ACTIONSELECTIONS); 
    memset(d_averageMaxCurrentQValue, 0, sizeof(float) * ACTIONSELECTIONS); 
    d_steps = 0;
    d_exit = false;
    d_countSolves = 0;
    d_stepEpoch = 0;
    d_p = 0.9;
    d_Alpha = 0.5;
    d_Beta = 0.65;
    for (d_runs = 0; d_runs < 5; ++d_runs)
    {       
        runMaze(mazeGrid);
        //Calculating the average max q value over the current amount of runs.
        fillAverageQValue(d_maxCurrentQValue);
        //Reset the array that stores the max Q-value.
        memset(d_maxCurrentQValue, 0, sizeof(float) * ACTIONSELECTIONS);
    }
    cout << "Begin" << endl;
    printPolicy(mazeGrid);
    cout << "DONE" <<endl;
    //Printing the result from 'fillAverageQValue'
    print(d_averageMaxCurrentQValue);
    
}


void print(float* Qarray)
{
    ofstream txtOut;
    txtOut.open ("output.txt");
    for(int count = 0; count < ACTIONSELECTIONS; count ++)
        txtOut << Qarray[count] << ", " ;//need to sum all q values 
}


