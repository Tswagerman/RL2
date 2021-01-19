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
        "|P|P|P|PPPP|",
        "|P|P|_P___P|",
        "|PPP|PPPP|P|",
        "|P|PPP|P|PP|",
        "|P|X_|PPP|P|",
        "|P|PP|P P|P|",
        "|PPP___|P|P|",
        "|_P|PPP|P|P|",
        "|PP__PPPP|P|",
        "|P|PP|_|P|P|",
        "|P|PP|P|P|P|",
        "|P|PPPP|P|P|",
        "|P|PP|PPPPP|",
        "|PPPP|P|__P|",
        "|P|__|_|PPP|",
        "|__________|",
    };
    size_t widthMaze = 12;
    size_t heightMaze = 18;
    size_t sizeMaze = widthMaze * heightMaze;
    std::vector<cell> mazeGrid;
    makeGrid(mazeGrid, widthMaze, heightMaze, maze);
    size_t start = getStartPos(mazeGrid, sizeMaze);
    mazeSolver solution(mazeGrid, widthMaze, heightMaze, start); 
    //print(mazeGrid, sizeMaze);
}

void print(std::vector<cell> const &input, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        input.at(i).print();
    }
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
