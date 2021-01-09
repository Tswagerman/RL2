#ifndef INCLUDED_MAZESOLVER_
#define INCLUDED_MAZESOLVER_
#include "../cell/cell.ih"

class mazeSolver
{
    size_t d_x;
    size_t d_y;
    size_t d_height;
    size_t d_width;
    size_t d_idxCell;
    int d_actionSelection;
    size_t d_runs;
    size_t d_steps;
    float* m_QValue;
    cell d_currentCell;
    public:
        mazeSolver();
        mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start);
        ~mazeSolver();

    private:
        void runMaze(vector<cell> &mazeGrid);
        int actionSelection();
        float actionValueFunc(std::vector<cell> const &input, int action, float discountRate, int step, float reward);
        void getMaxQValue();
};
        
#endif
