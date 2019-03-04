#include "Player.h"

Player::Player() {
    this->moves = 0;
    this->row = 0;
    this->col = 0;
}

int Player::GetRow()  {
    return row;
}

int Player::GetCol()  {
    return col;
}

void Player::SetPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

void Player::AddItem(std::string item) {
    this->items.push_back(item);
}

bool Player::HasItem(std::string item) {
    for(std::string it : items) {
        if(it == item ) {
            return true;
        }
    }
    return false;
}

void Player::UseItem(std::string item) {
    vector<string>::iterator it;
    bool found = false;
    for(it = items.begin(); it != items.end(); it++) {
        if(*it == item ) {
            found= true;
            break;
        }
    }
    if(found) {
        items.erase(it);
    }
}

int Player::GetMoveCount() {
    return moves;
}

void Player::IncrementMoves() {
    this->moves++;
}
