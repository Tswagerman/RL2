//#define XERR
#include "mazesolver.ih"

void print(float* Qarray)
{
    ofstream txtOut;
    txtOut.open ("output.txt");
    for(int count = 0; count < ACTIONSELECTIONS; count ++){
        txtOut << Qarray[count] << ", " ;
}
}

mazeSolver::mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start)
  : d_height(heightMaze),
    d_width(widthMaze),
    d_idxCell(start),
    d_start(start)
{
    d_currentCell = mazeGrid.at(d_idxCell);
    d_x = d_currentCell.getWidth();
    d_y = d_currentCell.getHeight();
    m_QValue = new float[SIZE]; //SIZE defined in cell.h
    d_maxCurrentQValue = new float[ACTIONSELECTIONS];
    //memset can be used to set array to 0    
    memset(d_maxCurrentQValue, 0, sizeof(float) * ACTIONSELECTIONS); 
    d_runs = 0;
    d_steps = 0;
    d_exit = false;
    d_countSolves = 0;
    //d_currentCell.print();
    cout << "BEFORE RUNMAZE#######" << endl << "idx = " << d_idxCell << endl;
    d_runs = 0;
    for (d_runs = 0; d_runs < 1; ++d_runs)
    {
        //mazeGrid = mazeGrid;        
        runMaze(mazeGrid);
        cout << "d_maxCurrentQValue" << endl;
        print(d_maxCurrentQValue);
        memset(d_maxCurrentQValue, 0, sizeof(float) * ACTIONSELECTIONS);
    }
}
