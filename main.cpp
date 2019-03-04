#include <iostream>

#include "Room.h"
#include "Passage.h"
#include "Player.h"
#include "Maze.h"
#include "Game.h"

#define REQUIRE(x) cout<<x<<endl;
#define TEST_CASE(x) cout<<x<<endl;

int main() {

    Maze* newMaze = new Maze("testMaze.txt");
    Player* newPlayer = new Player();
    Game newGame(newMaze, newPlayer);
    cout<<"****************** Welcome to MAze Game ******************"<<endl;
    while (!newGame.ExitFound()) {
        newGame.printGame();
        cout<<"Enter the direction in which you want to move."<<endl;
        cout<<"1. North"<<endl;
        cout<<"2. East"<<endl;
        cout<<"3. South"<<endl;
        cout<<"4. West"<<endl;
        int m;
        do{
            cin>>m;
        }
        while (m<1 || m>4);
        switch (m) {
            case 1: newGame.MoveDirection("N");
                break;
            case 2: newGame.MoveDirection("E");
                break;
            case 3: newGame.MoveDirection("S");
                break;
            case 4: newGame.MoveDirection("W");
                break;
        }
    }

    cout<<"****************Game Finished ******************"<<endl;

    return 0;
}