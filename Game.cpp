#include "Game.h"

std::string Game::GetPassageDescription(Passage *passage) {
    if(passage->IsOpen()) {
        return "Open Passage";
    }
    else if(passage->RequiresKey()) {
        return "Doorway Requiring Key";
    }
    else{
        return "Solid Wall";
    }
}

Game::Game(Maze *maze, Player *player) {
    this->maze = maze;
    this->player = player;
    this->currentRoom = maze->GetRoom(0,0);
    string nextItem = currentRoom->AcquireNextItem();
    while (nextItem != "") {
        this->currentItems.push_back(nextItem);
        nextItem = currentRoom->AcquireNextItem();
    }
}

void Game::DisplayItems() {
    string nextItem = currentRoom->AcquireNextItem();
    cout<<"[ ";
    while (nextItem != "") {
        cout<<nextItem<<" ";
        nextItem = currentRoom->AcquireNextItem();
    }
    cout<<" ]"<<endl;
}

void Game::DisplayPassages() {

    if(currentRoom->GetNorthPassage()->IsOpen()  ) {
        cout<<"Open North Passage"<<endl;
    }
    else if(currentRoom->GetNorthPassage()->RequiresKey()) {
        cout<<"Doorway North Passage"<<endl;
    }

    if(currentRoom->GetEastPassage()->IsOpen()  ) {
        cout<<"Open East Passage"<<endl;
    }
    else if(currentRoom->GetEastPassage()->RequiresKey()) {
        cout<<"Doorway East Passage"<<endl;
    }

    if(currentRoom->GetSouthPassage()->IsOpen()  ) {
        cout<<"Open South Passage"<<endl;
    }
    else if(currentRoom->GetSouthPassage()->RequiresKey()) {
        cout<<"Doorway South Passage"<<endl;
    }

    if(currentRoom->GetWestPassage()->IsOpen()  ) {
        cout<<"Open West Passage"<<endl;
    }
    else if(currentRoom->GetWestPassage()->RequiresKey()) {
        cout<<"Doorway West Passage"<<endl;
    }

}

std::string Game::GetCurrentRoomName() {
    return currentRoom->GetName();
}

void Game::LootRoom() {
    string nextItem = currentRoom->AcquireNextItem();
    while (nextItem != "") {
        this->currentItems.push_back(nextItem);
        player->AddItem(nextItem);
        nextItem = currentRoom->AcquireNextItem();
    }
}

bool Game::ValidDirection(std::string direction) {
    if(direction=="N") {
        if(currentRoom->GetNorthPassage()->IsOpen()) {
            return true;
        }
        else if(currentRoom->GetNorthPassage()->RequiresKey() && player->HasItem(currentRoom->GetNorthPassage()->GetRequiredKey())) {
            string item = currentRoom->GetNorthPassage()->GetRequiredKey();
            player->UseItem(item);
            vector<string>::iterator it;
            bool found = false;
            for(it = currentItems.begin(); it != currentItems.end(); it++) {
                if(*it == item ) {
                    found= true;
                    break;
                }
            }
            if(found) {
                currentItems.erase(it);
            }
            return true;
        }
    }
    else if(direction=="E") {
        if(currentRoom->GetEastPassage()->IsOpen()) {
            return true;
        }
        else if(currentRoom->GetEastPassage()->RequiresKey() && player->HasItem(currentRoom->GetEastPassage()->GetRequiredKey())) {
            string item = currentRoom->GetEastPassage()->GetRequiredKey();
            player->UseItem(item);
            vector<string>::iterator it;
            bool found = false;
            for(it = currentItems.begin(); it != currentItems.end(); it++) {
                if(*it == item ) {
                    found= true;
                    break;
                }
            }
            if(found) {
                currentItems.erase(it);
            }
            return true;
        }
    }
    else if(direction=="S") {
        if(currentRoom->GetSouthPassage()->IsOpen()) {
            return true;
        }
        else if(currentRoom->GetSouthPassage()->RequiresKey() && player->HasItem(currentRoom->GetSouthPassage()->GetRequiredKey())) {
            string item = currentRoom->GetSouthPassage()->GetRequiredKey();
            player->UseItem(item);
            vector<string>::iterator it;
            bool found = false;
            for(it = currentItems.begin(); it != currentItems.end(); it++) {
                if(*it == item ) {
                    found= true;
                    break;
                }
            }
            if(found) {
                currentItems.erase(it);
            }
            return true;
        }
    }
    else if(direction=="W") {
        if(currentRoom->GetWestPassage()->IsOpen()) {
            return true;
        }
        else if(currentRoom->GetWestPassage()->RequiresKey() && player->HasItem(currentRoom->GetWestPassage()->GetRequiredKey())) {
            string item = currentRoom->GetWestPassage()->GetRequiredKey();
            player->UseItem(item);
            vector<string>::iterator it;
            bool found = false;
            for(it = currentItems.begin(); it != currentItems.end(); it++) {
                if(*it == item ) {
                    found= true;
                    break;
                }
            }
            if(found) {
                currentItems.erase(it);
            }
            return true;
        }
    }
    return false;
}

void Game::MoveDirection(std::string direction) {
    if(ValidDirection(direction)) {
        int r = player->GetRow();
        int c = player->GetCol();
        if(direction=="N") {
            currentRoom = maze->GetRoom(r-1,c);
            player->SetPosition(r-1,c);
        }
        else if(direction=="E") {
            currentRoom = maze->GetRoom(r,c+1);
            player->SetPosition(r,c+1);
        }
        else if(direction=="S") {
            currentRoom = maze->GetRoom(r+1,c);
            player->SetPosition(r+1,c);
        }
        else if(direction=="W") {
            currentRoom = maze->GetRoom(r,c-1);
            player->SetPosition(r,c-1);
        }
        this->LootRoom();
        player->IncrementMoves();
    }
}

bool Game::ExitFound() {
    if(currentRoom->GetName().compare("The Exit!")==0){
        return true;
    }
    return false;
}

void Game::printGame() {
    cout<<"Player current position is :"<<endl;
    cout<<"Row :"<<this->player->GetRow()<<" ";
    cout<<"Col :"<<this->player->GetCol()<<endl;
    cout<<"Player is Room : "<<currentRoom->GetName()<<endl;
    cout<<"Player has collected the following items :"<<endl;
    for (string item:this->currentItems) {
        cout<<item<<", ";
    }
    cout<<endl;
    cout<<"Number of Moves by player: "<<this->player->GetMoveCount()<<endl;
    cout<<"Current status os maze is: "<<endl;
    this->maze->printMaze();
}
