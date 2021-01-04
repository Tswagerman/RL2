#include <cstdlib>
#include <iostream>
#include "cell/cell.ih"
#include "mazesolver/mazesolver.ih"
#include <vector>
using namespace std;

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
        cout << "height loop through maze" << endl;
        for (size_t width = 0; width < widthMaze; ++width)
        {
            const char* character = maze[height];     
            cout << "character = " << character[width] << endl;
            cell currentCell(width, height, character[width]);   
            mazeGrid.push_back(currentCell);                  
        }
    }
    cout << "Done filling in mazegrid" << endl;
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

int main()
{
    const char* maze[12] = {
        "_S_________",
        "| |     |G|",
        "| |  |  | |",
        "| |  | _| |",
        "|  _ |   _|",
        "| |  | | | ",
        "|_|__| | | ",
        "|G|  |T  | ",
        "| | ___| | ",
        "|      | | ",
        "|      | | ",
        "|X_______| ",
    };
    size_t widthMaze = 11;
    size_t heightMaze = 12;
    size_t sizeMaze = widthMaze * heightMaze;
    std::vector<cell> mazeGrid;
    makeGrid(mazeGrid, widthMaze, heightMaze, maze);;
    size_t start = getStartPos(mazeGrid, sizeMaze);
    print(mazeGrid, sizeMaze);
    //recursive reward finding solution
    //mazeSolver solution(mazeGrid, widthMaze, heightMaze, start); 
}
