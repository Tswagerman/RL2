//#define XERR
#include "mazesolver.ih"
void mazeSolver::printPolicy(std::vector<cell> &mazeGrid)
{
    int direction;
    size_t position;
    for (size_t height = 0; height < d_height; ++height)
    {
        for (size_t width = 0; width < d_width; ++width)
        {
            position = (height * d_width) + width; 
            if (mazeGrid.at(position).getBorder() == true)
                cout << 'B'; 
            else if (mazeGrid.at(position).getExit() == true)
                cout << 'G';
            else
            {
                //mazeGrid.at(position).print();
                direction = selectAction(mazeGrid.at(position).getQValue());
                switch(direction)
                {
                case(0):
                    cout << 'N'; 
                    break;
                case(1):
                    cout << 'E'; //East
                    break;
                case(2):
                    cout << 'S'; //South
                    break;
                case(3):
                    cout << 'W'; //West
                    break;
                }
            }
            
        }
        cout << endl;            
    }
}
