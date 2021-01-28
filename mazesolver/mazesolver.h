#ifndef INCLUDED_MAZESOLVER_
#define INCLUDED_MAZESOLVER_
#include "../cell/cell.ih"

#define ACTIONSELECTIONS 10000

class mazeSolver
{
    size_t d_alg;
    size_t d_x;
    size_t d_y;
    size_t d_height;
    size_t d_width;
    size_t d_idxCell;
    size_t d_start;
    size_t d_actionSelection;
    size_t d_runs;
    size_t d_steps;
    size_t d_countSolves;
    int d_action;
    float d_maxQ;
    float m_p;
    bool d_exit;
    cell d_currentCell;
    cell d_nextCell;

    float *m_QValue;
    float *m_QValueB;
    float *d_maxCurrentQValue;
    float *d_averageMaxCurrentQValue;
    float *d_sarsa;
    public:
        mazeSolver();
        mazeSolver(vector<cell> &mazeGrid, size_t widthMaze, size_t heightMaze, size_t start,
             size_t algorithm);
        ~mazeSolver();

    private:
        void runMaze(vector<cell> &mazeGrid);
        void reset(std::vector<cell> &mazeGrid);
        void fillAverageQValue(float* Qarray);
        void printPolicy(std::vector<cell> &input);

        void qLearning();
        void rLearning();
        void sarsa();
        void doubleQlearning();

        size_t selectAction(float* QValue);
        size_t getOpt(float* array) const;
        int action(size_t actionSelection);
        float getMaxQ(float* input) const;
        
        std::vector<cell> setMazeQToZero(std::vector<cell> &mazeGrid);
};
        
#endif
