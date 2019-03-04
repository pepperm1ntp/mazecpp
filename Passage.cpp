#include "Passage.h"

Passage::Passage() {}

Passage::Passage(bool isOpen) {
    this->isOpen = isOpen;
}

bool Passage::IsOpen() {
    return isOpen;
}

Passage::Passage(bool isOpen, std::string key) {
    this->isOpen = isOpen;
    this->key = key;
}

bool Passage::RequiresKey() {
    return (this->key != "");
}

string Passage::GetRequiredKey() {
    return this->key;
}

void Passage::Open() {
    this->isOpen = true;
}
