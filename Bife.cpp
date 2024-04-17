//
// Created by Diogo on 15/12/2022.
//

#include "Bife.h"

const string Bife::NAME = "bife";
const vector<string> Bife::SMELLS = { "carne", "ketchup" };

Bife::Bife(int id, int x, int y) :
        Food(id, x, y, NUTRIPOINTS, TOXICPOINTS) {

}
Bife::Bife(const Bife &other) :
        Food(this->getId(), this->getCol(), this->getRow(), NUTRIPOINTS, TOXICPOINTS)
    {

}

const string &Bife::getName() const {
    return NAME;
}

const char Bife::getLetter() const {
    return LETTER;
}

const vector<string> &Bife::getSmells() const {
    return SMELLS;
}

Food *Bife::duplicate() const {
    return new Bife(*this);
}




