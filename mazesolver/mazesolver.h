#ifndef INCLUDED_MAZESOLVER_
#define INCLUDED_MAZESOLVER_
#include "../cell/cell.ih"

#define ACTIONSELECTIONS 10000

class mazeSolver
{
    size_t d_x;
    size_t d_y;
    size_t d_height;
    size_t d_width;
    size_t d_idxCell;
    size_t d_start;
    int d_actionSelection;
    int d_action;
    size_t d_runs;
    size_t d_steps;
    size_t d_countSolves;
    float d_maxQ;
    float *m_QValue;
    float *d_maxCurrentQValue;
    bool d_exit;
    cell d_currentCell;
    std::stack <int> d_sAction;
    std::stack <float> d_sQValue;
    public:
        mazeSolver();
        mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start);
        ~mazeSolver();

    private:
        void runMaze(vector<cell> &mazeGrid);
        int action(size_t actionSelection);
        float actionValueFunc(std::vector<cell> &input, int step, float reward, size_t idxCell);
        size_t selectAction(float* QValue);
        float getMaxQ(float* input) const;
        void reset(std::vector<cell> &mazeGrid);
};
        
#endif
