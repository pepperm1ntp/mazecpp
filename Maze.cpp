#include "Maze.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


Maze::Maze(std::string mazeFile) {
    this->mazeFile.open(mazeFile);
    LoadMaze();
}

Maze::~Maze() {

}

Room *Maze::GetRoom(int row, int col) {
    if(0<= row && row < this->rows && 0<= col && col < this->cols ) {
        return rooms[row]+col;
    }
    return nullptr;
}

int Maze::GetNumberRows() {
    return this->rows;
}

int Maze::GetNumberCols() {
    return this->cols;
}

void Maze::LoadMaze() {
    this->mazeFile>>this->rows;
    this->mazeFile>>this->cols;
    rooms = new Room*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        rooms[i] = new Room[this->cols];
    }
    std::string line;
    vector<string> items;
    getline(this->mazeFile,line);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            getline(this->mazeFile,line);
            stringstream sline(line);
            string name;
            Passage *northPassge,*westPassage,*southPassage,*eastPassage;
            string str;
            for (int k = 0; k < 6; ++k) {
                getline(sline, str, ',');
                switch (k) {
                    case 0: name = str;
                            break;
                    case 1: northPassge = CreatePassage(str);
                        break;
                    case 2: eastPassage = CreatePassage(str);
                        break;
                    case 3: southPassage = CreatePassage(str);
                        break;
                    case 4: westPassage = CreatePassage(str);
                        rooms[i][j] = *new Room(name,northPassge,eastPassage,southPassage,westPassage);
                        break;
                    case 5: if(!str.empty()) {
                            string item1;
                            stringstream collected_items(str);
                            while (collected_items.good()) {
                                collected_items>>item1;
                                rooms[i][j].AddItem(item1);
                            }
                    }
                }
            }
        }
    }
}

Passage *Maze::CreatePassage(std::string type) {
    Passage *newPassage;
    if(type=="-") {
        newPassage = new Passage(false);
    }
    else if(type=="+") {
        newPassage = new Passage(true);
    }
    else {
        newPassage = new Passage(false,type);
    }
    return newPassage;
}

void Maze::printMaze() {


    for (int i = 0; i < this->rows; ++i) {
        cout<<"  ";
        for (int j = 0; j < 26*this->cols; ++j) {
            cout<<"-";
        }
        cout<<endl;
        cout<<" | ";
        for (int j = 0; j < this->cols; ++j) {
            printf("%25s |",rooms[i][j].GetName().c_str());
        }
        cout<<endl;

    }
    cout<<"  ";
    for (int j = 0; j < 26*this->cols; ++j) {
        cout<<"-";
    }
    cout<<endl;

}
