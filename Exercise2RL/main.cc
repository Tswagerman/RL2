#include <cstdlib>
#include <iostream>
#include "cell/cell.ih"
using namespace std;

int main()
{
    const char* mazeGrid[12] = {
        "_S________",
        "| |     ||",
        "| |  |  ||",
        "| |  | _||",
        "|  _ |   |",
        "| |  | | |",
        "|_|__| | |",
        "| |  |   |",
        "| | ___| |",
        "|      | |",
        "|      | |",
        "|X_______|",
    };
    size_t widthMaze = 10;
    size_t heightMaze = 12;
    cell* solution[widthMaze * heightMaze];
    for (size_t height = 0; height < heightMaze; ++height)
    {
        for (size_t width = 0; width < widthMaze; ++width)
        {
            const char* character = mazeGrid[height];
            //cout << "character = " << character[width] << endl;            
            cell currentCell(width, height, character[width]);            
            solution[width * 10 + height] = currentCell;
            
        }
        //std::cout << mazeGrid[height] << endl;
    }
    
}
