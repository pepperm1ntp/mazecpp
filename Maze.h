#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include "Room.h"

class Maze {

private:
    Room** rooms;
    int rows;
    int cols;
    std::ifstream mazeFile;

public:

    void LoadMaze();
    Passage* CreatePassage(std::string type);

    Maze(std::string mazeFile);

    Room* GetRoom(int row,int col);
    int GetNumberRows();
    int GetNumberCols();

    virtual ~Maze();

    void printMaze();

};


#endif //MAZE_H
