//
// Created by Diogo on 12/12/2022.
//

#include "Lobo.h"

const string Lobo::FOOD_SMELL = "Carne";
const string Lobo::NAME = "Lobo";

Lobo::Lobo(int i, int x, int y, int instant) :
        Animal(i, INIT_WEIGHT, INIT_HEALTH, LIFE_SPAN, x, y,
               METABOLISM, HUNGRY_MS1, HUNGRY_MS2,
               rand() % (MAX_BIRTH_CYCLE - MIN_BIRTH_CYCLE) + MIN_BIRTH_CYCLE,
               BIRTH_DIST, instant, SMELLING_RANGE) {
    hasReproduced = false;
}

Lobo::Lobo(const Lobo &other) :
        Animal(this->getId(), INIT_WEIGHT, INIT_HEALTH, LIFE_SPAN, this->getCol(),
               this->getRow(), METABOLISM, HUNGRY_MS1,
               HUNGRY_MS2, rand() % (MAX_BIRTH_CYCLE - MIN_BIRTH_CYCLE),
               BIRTH_DIST, this->getBirthInstant(), SMELLING_RANGE) {

    for (const string& str : other.getHistory())
        addHistory(str);

    this->hasReproduced = other.hasReproduced;
}

const string &Lobo::getName() const {
    return NAME;
}

const char Lobo::getLetter() const {
    return LETTER;
}

Animal *Lobo::duplicate() const {
    return new Lobo(*this);
}
