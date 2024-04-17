//
// Created by Diogo on 27/12/2022.
//

#include "Corpo.h"

const string Corpo::NAME = "corpo";
const vector<string> Corpo::SMELLS = {"carne"};

Corpo::Corpo(int id, int x, int y, int nutriPoints, int toxicPoints) :
        Food(id, x, y, nutriPoints, toxicPoints), MAXTOXICPOINTS(nutriPoints * 2) {

}

Corpo::Corpo(const Corpo &other) :
        Food(this->getId(), this->getCol(), this->getRow(),
             this->getNutriPoints(),this->getToxicPoints()),MAXTOXICPOINTS(this->getNutriPoints() * 2)
{

}


const string &Corpo::getName() const {
    return NAME;
}

const char Corpo::getLetter() const {
    return LETTER;
}

const vector<string> &Corpo::getSmells() const {
    return SMELLS;
}

Food *Corpo::duplicate() const {
    return new Corpo(*this);
}

