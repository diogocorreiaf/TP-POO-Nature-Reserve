//
// Created by Diogo on 12/12/2022.
//

#include "Canguru.h"

//const string Canguru::FOOD_SMELL = "verdura";
const string Canguru::NAME = "Canguru";

Canguru::Canguru(int i, int x, int y, int instant) :
        Animal(i, rand() % (MAX_WEIGHT - MIN_WEIGHT) + MIN_WEIGHT,
               INIT_HEALTH, LIFE_SPAN, x, y,METABOLISM,
               HUNGRY_MS1, HUNGRY_MS2,BIRTH_CICLE,
               BIRTH_DIST,instant, SMELLING_RANGE) {

}

Canguru::Canguru(const Canguru &other) :
        Animal(this->getId(), rand() % (MAX_WEIGHT - MIN_WEIGHT) +
                              MIN_WEIGHT, INIT_HEALTH, LIFE_SPAN,
                              this->getCol(),this->getRow(), METABOLISM,
                              HUNGRY_MS1,HUNGRY_MS2, BIRTH_CICLE,
               BIRTH_DIST, this->getBirthInstant(),SMELLING_RANGE) {

    for (const string& str : other.getHistory())
        addHistory(str);
}

const string &Canguru::getName() const {
    return NAME;
}

const char Canguru::getLetter() const {
    return LETTER;
}

Animal *Canguru::duplicate() const {
    return new Canguru(*this);
}


#include "Canguru.h"
