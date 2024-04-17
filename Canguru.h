//
// Created by Diogo on 12/12/2022.
//

#ifndef FOOD_CPP_CANGURU_H
#define FOOD_CPP_CANGURU_H


#include "Animal.h"

class Canguru : public Animal {
    // region Constantes
    const static int INIT_HEALTH = 20;
    const static int MIN_WEIGHT = 1;
    const static int MAX_WEIGHT = 4;
    const static int LIFE_SPAN = 70;
    const static int METABOLISM = 0;
    const static int HUNGRY_MS1 = 10;
    const static int HUNGRY_MS2 = 20;
    const static int BIRTH_CICLE = 30;
    const static int BIRTH_DIST = 3;
    const static int SMELLING_RANGE = 7;
    //const static string FOOD_SMELL;
    const static string NAME;
    // endregion

public:
    const static char LETTER = 'g';
    Canguru(int i, int x, int y, int instant);
    Canguru(const Canguru& other);

    const string& getName() const override;
    const char getLetter() const override;
    Animal* duplicate() const override;

};

#endif //FOOD_CPP_CANGURU_H
