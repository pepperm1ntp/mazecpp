
#include <iostream>
#include <string>
#include <vector>

using namespace std;


#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int row;
    int col;
    int moves;
    vector<string> items;

public:
    Player();

    int GetRow() ;
    int GetCol() ;
    void SetPosition(int row,int col);

    void AddItem(std::string item);
    bool HasItem(std::string item);
    void UseItem(std::string item);

    int GetMoveCount();
    void IncrementMoves();
};


#endif //PLAYER_H
