//
// Created by Diogo on 12/12/2022.
//

#ifndef FOOD_CPP_LOBO_H
#define FOOD_CPP_LOBO_H


#include "Animal.h"

class Lobo : public Animal {
    // region Constantes
    const static int INIT_HEALTH = 25;
    const static int INIT_WEIGHT = 15;
    const static int LIFE_SPAN = 30;
    const static int METABOLISM = 2;
    const static int HUNGRY_MS1 = 10;
    const static int HUNGRY_MS2 = 20;
    const static int BIRTH_DIST = 15;
    const static int SMELLING_RANGE = 5;
    const static string FOOD_SMELL;
    const static string NAME;
    const static int MAX_BIRTH_CYCLE = 5;
    const static int MIN_BIRTH_CYCLE = 40;
    // endregion

    bool hasReproduced;

public:
    const static char LETTER = 'l';
    Lobo(int i, int x, int y, int instant);
    Lobo(const Lobo& other);

    const string& getName() const override;
    const char getLetter() const override;
    Animal* duplicate() const override;
};



#endif //FOOD_CPP_LOBO_H
