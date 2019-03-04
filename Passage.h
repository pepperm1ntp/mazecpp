
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef PASSAGE_H
#define PASSAGE_H


class Passage {

private:
    bool isOpen;
    string key;
public:
    Passage();

    Passage(bool isOpen);

    Passage(bool isOpen, std::string key);

    bool IsOpen();

    bool RequiresKey();
    string GetRequiredKey();

    void Open();

};


#endif //PASSAGE_H
