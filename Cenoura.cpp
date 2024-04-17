//
// Created by Diogo on 27/12/2022.
//

#include "Cenoura.h"

const string Cenoura::NAME = "cenoura";
const vector<string> Cenoura::SMELLS = {"verdura"};


Cenoura::Cenoura(int id, int x, int y) :
        Food(id, x, y, NUTRIPOINTS, TOXICPOINTS) {

}
Cenoura::Cenoura(const Cenoura &other) :
        Food(this->getId(), this->getCol(), this->getRow(), NUTRIPOINTS, TOXICPOINTS)
{

}

const string &Cenoura::getName() const {
    return NAME;
}

const char Cenoura::getLetter() const {
    return LETTER;
}

const vector<string> &Cenoura::getSmells() const {
    return SMELLS;
}

Food *Cenoura::duplicate() const {
    return new Cenoura(*this);
}


