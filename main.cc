#include <cstdlib>
#include <iostream>
#include "cell/cell.ih"
#include "mazesolver/mazesolver.ih"
#include <vector>
using namespace std;
void print(std::vector<cell> const &input, size_t size);
void makeGrid(std::vector<cell>& mazeGrid, size_t widthMaze, size_t heightMaze, const char** maze);
size_t getStartPos(std::vector<cell> mazeGrid, size_t size);

int main()
{
       /* const char* maze[18] = {
        "___________",
        "|S|PPPPP|P|",
        "|P|PP|PP|P|",
        "|PPPP|P_|P|",
        "|P _P|PPPP|",
        "|P|PP|P|PP|",
        "|P|__|P|P |",
        "|P|PP|P PP|",
        "|P|P___|PP|",
        "|PPPPPP|PP|",
        "|PPPPPPPPP|",
        "|P|PP|P|PP|",
        "|P|PP|P|PP|",
        "|P|PP|P|PP|",
        "|P|PP|P|PP|",
        "|P|PP|P|PP|",
        "|P|PP|P|PP|",
        "|X________|",
    };*/
/*const char* maze[12] = {
        "___________",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|SPPPPPPPP|",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|PPPPPPPPP| ",
        "|X________| ",
    };*/
const char* maze[18] = {
        "____________",
        "|S|PPPPP|PP|",
        "|PPPP|PP|PP|",
        "|P|PP|P_|PP|",
        "|P|_PPPPP|P|",
        "|P|PPP|P|PP|",
        "|P|P_|PPP|P|",
        "|P|PP|PPP|P|",
        "|PPP___|P|P|",
        "|PPPPPP|P|P|",
        "|_|PPPPPP|P|",
        "|P|__|_|P|P|",
        "|P|PP|P|P|P|",
        "|P|PPPP|P|P|",
        "|P|PP|PPPPP|",
        "|PPPP|P|PPP|",
        "|P|__|_|PPP|",
        "|X_________|",
    };
    size_t widthMaze = 12;
    size_t heightMaze = 18;
    size_t sizeMaze = widthMaze * heightMaze;
    size_t algorithm = -1;
    std::vector<cell> mazeGrid;
    makeGrid(mazeGrid, widthMaze, heightMaze, maze);
    size_t start = getStartPos(mazeGrid, sizeMaze);    
    cout << "Pick an Algorithm: 0) Q-Learning, 1) r-Learning, 2) Sarsa." << endl
        << "Provide a number: ";
    cin >> algorithm;
    if ((algorithm < 0) | (algorithm > 2))
    {
        cout << "Wrong input!" << endl;
        return -1;
    }
    mazeSolver solution(mazeGrid, widthMaze, heightMaze, start, algorithm); 
}

void print(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < size; i++) 
        input.at(i).print();
}

void makeGrid(std::vector<cell>& mazeGrid, size_t widthMaze, size_t heightMaze, const char** maze)
{
    //looping through the entire maze, filling the grid
    for (size_t height = 0; height < heightMaze; ++height)
    {
        for (size_t width = 0; width < widthMaze; ++width)
        {
            const char* character = maze[height];     
            cell currentCell(width, height, character[width]);   
            mazeGrid.push_back(currentCell);                  
        }
    }
}

size_t getStartPos(std::vector<cell> mazeGrid, size_t size)
{
    for (size_t increment = 0; increment < size; ++increment)
    {
        if (mazeGrid.at(increment).getStart() == true)
            return increment;
    }
    return 0;
}
