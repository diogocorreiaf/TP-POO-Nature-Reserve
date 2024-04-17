//
// Created by Diogo on 15/12/2022.
//

#include "Relva.h"

const string Relva::NAME = "relva";
const vector<string> Relva::SMELLS = { "erva", "verdura" };

Relva::Relva(int id, int x, int y) :
        Food(id, x, y, NUTRIPOINTS, TOXICPOINTS) {

}

Relva::Relva(const Relva &other) :
        Food(this->getId(), this->getCol(), this->getRow(), NUTRIPOINTS, TOXICPOINTS)
{

}

const string &Relva::getName() const {
    return NAME;
}

const char Relva::getLetter() const {
    return LETTER;
}

const vector<string> &Relva::getSmells() const {
    return SMELLS;
}



Food *Relva::duplicate() const {
    return new Relva(*this);
}
