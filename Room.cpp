#include "Room.h"

Room::Room() {}

Room::Room(string name, Passage *northPassage, Passage *eastPassage, Passage *southPassage, Passage *westPassage) {

    this->name = name;
    this->northPassage = northPassage;
    this->southPassage = southPassage;
    this->eastPassage = eastPassage;
    this->westPassage = westPassage;
}

string Room::GetName() {
    return name;
}

Passage* Room::GetNorthPassage() {
    return northPassage;
}

Passage* Room::GetEastPassage() {
    return eastPassage;
}

Passage* Room::GetSouthPassage() {
    return southPassage;
}

Passage* Room::GetWestPassage() {
    return westPassage;
}

void Room::AddItem(string item) {
    this->items.push_back(item);
}

string Room::AcquireNextItem() {
    string lastItem;
    if(this->items.size()>0) {
        lastItem = this->items.back();
        this->items.pop_back();
    }
    return lastItem;
}

