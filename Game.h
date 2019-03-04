#ifndef GAME_H
#define GAME_H


#include "Maze.h"
#include "Player.h"
#include <vector>

class Game {

    Maze* maze;
    Player* player;
    Room* currentRoom;
    std::vector<std::string> currentItems;

public:

    std::string GetPassageDescription(Passage* passage);

    Game(Maze* maze, Player* player);

    void DisplayItems();
    void DisplayPassages();
    std::string GetCurrentRoomName();
    void LootRoom();
    bool ValidDirection(std::string direction);
    void MoveDirection(std::string direction);
    bool ExitFound();

    void printGame();


};


#endif //GAME_H
