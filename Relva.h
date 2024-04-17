//
// Created by Diogo on 15/12/2022.
//

#ifndef FOOD_CPP_RELVA_H
#define FOOD_CPP_RELVA_H


#include "Food.h"

class Relva : public Food {
    const static string NAME;
    const static int LIFESPAN = 20;
    const static int NUTRIPOINTS = 3;
    const static int TOXICPOINTS = 0;
    const static int BIRTHCYCLE = LIFESPAN * 75 / 100;
    const static vector<string> SMELLS;

public:
    const static char LETTER = 'r';
    Relva(int id, int x, int y);
    Relva(const Relva& other);

    const string& getName() const override;
    const char getLetter() const override;
    const vector<string> &getSmells() const override;

    Food* duplicate() const override;

};


#endif //FOOD_CPP_RELVA_H
