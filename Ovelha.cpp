//
// Created by Diogo on 12/12/2022.
//

#include "Ovelha.h"

const string Ovelha::FOOD_SMELL = "erva";
const string Ovelha::NAME = "Ovelha";

Ovelha::Ovelha(int i, int x, int y,int instant , int hp) :
        Animal(i, rand() % (MAX_WEIGHT - MIN_WEIGHT) +
                  MIN_WEIGHT, hp, LIFE_SPAN, x, y,
               METABOLISM, HUNGRY_MS1, HUNGRY_MS2,
               BIRTH_CICLE, BIRTH_DIST, instant, SMELLING_RANGE) {

}

Ovelha::Ovelha(const Ovelha &other) :
        Animal(this->getId(), rand() % (MAX_WEIGHT - MIN_WEIGHT) +
                              MIN_WEIGHT, this->getHealth(), LIFE_SPAN, this->getCol(),
               this->getRow(), METABOLISM, HUNGRY_MS1,
               HUNGRY_MS2, BIRTH_CICLE, BIRTH_DIST, this->getBirthInstant(), SMELLING_RANGE) {

    for (const string &str: other.getHistory())
        addHistory(str);
}


const string &Ovelha::getName() const {
    return NAME;
}

const char Ovelha::getLetter() const {
    return LETTER;
}

Animal *Ovelha::duplicate() const {
    return new Ovelha(*this);
}

