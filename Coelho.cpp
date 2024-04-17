//
// Created by Diogo on 12/12/2022.
//

#include "Coelho.h"

const string Coelho::FOOD_SMELL = "verdura";
const string Coelho::NAME = "Coelho";

Coelho::Coelho(int i, int x, int y, int instant) :
        Animal(i, rand() % (MAX_WEIGHT - MIN_WEIGHT) +
                  MIN_WEIGHT, INIT_HEALTH, LIFE_SPAN, x, y,
               METABOLISM, HUNGRY_MS1, HUNGRY_MS2,
               BIRTH_CICLE, BIRTH_DIST, instant, SMELLING_RANGE) {

}

Coelho::Coelho(const Coelho &other) :
        Animal(this->getId(), rand() % (MAX_WEIGHT - MIN_WEIGHT) +
                              MIN_WEIGHT, INIT_HEALTH, LIFE_SPAN, this->getCol(),
               this->getRow(), METABOLISM, HUNGRY_MS1,
               HUNGRY_MS2, BIRTH_CICLE, BIRTH_DIST, this->getBirthInstant(), SMELLING_RANGE) {

    for (const string& str : other.getHistory())
        addHistory(str);
}

const string &Coelho::getName() const {
    return NAME;
}

 const char Coelho::getLetter() const {
    return LETTER;
}

Animal *Coelho::duplicate() const {
    return new Coelho(*this);
}
