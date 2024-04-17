//
// Created by Diogo on 12/12/2022.
//

#ifndef FOOD_CPP_OVELHA_H
#define FOOD_CPP_OVELHA_H


#include "Animal.h"

class Ovelha : public Animal {
    // region Constantes
    const static int INIT_HEALTH = 20;
    const static int MIN_WEIGHT = 1;
    const static int MAX_WEIGHT = 4;
    const static int METABOLISM = 1;
    const static int HUNGRY_MS1 = 10;
    const static int HUNGRY_MS2 = 20;
    const static int BIRTH_CICLE = 8;
    const static int BIRTH_DIST = 10;
    const static int SMELLING_RANGE = 3;
    const static string FOOD_SMELL;
    const static string NAME;
    // endregion

public:
    const static char LETTER = 'o';
    const static int LIFE_SPAN = 30;
    Ovelha(int i, int x, int y,int instant ,int hp = INIT_HEALTH);
    Ovelha(const Ovelha& other);

    const string& getName() const override;
    const char getLetter() const override;

    Animal* duplicate() const override;
};


#endif //FOOD_CPP_OVELHA_H
