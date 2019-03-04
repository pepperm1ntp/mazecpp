
#include <iostream>
#include <string>
#include <vector>
#include "Passage.h"

using namespace std;

#ifndef ROOM_H
#define ROOM_H


class Room {
private:
    string name;
    vector<string> items;

    Passage *northPassage;
    Passage *eastPassage;
    Passage *southPassage;
    Passage *westPassage;

public:

    Room();

    Room(string name, Passage *northPassage, Passage *eastPassage, Passage *southPassage,
         Passage *westPassage);

    string GetName() ;

    Passage *GetNorthPassage() ;

    Passage *GetEastPassage() ;

    Passage *GetSouthPassage() ;

    Passage *GetWestPassage() ;

    void AddItem(string item);
    string AcquireNextItem();

};


#endif //ROOM_H
