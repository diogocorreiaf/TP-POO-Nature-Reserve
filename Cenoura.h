//
// Created by Diogo on 27/12/2022.
//

#ifndef FOOD_CPP_CENOURA_H
#define FOOD_CPP_CENOURA_H


#include "Food.h"

class Cenoura : public Food {
    const static string NAME;
    const static int NUTRIPOINTS = 4;
    const static int TOXICPOINTS = 0;
    const static int MAXTOXICPOINTS = 3;
    const static int TOXICPOINTSCYCLE = 10;
    const static vector<string> SMELLS;
public:
    const static char LETTER = 't';

    Cenoura(int id, int x, int y);
    Cenoura(const Cenoura& other);

    const string& getName() const override;
    const char getLetter() const override;
    const vector<string> &getSmells() const override;

    Food* duplicate() const override;
};


#endif //FOOD_CPP_CENOURA_H
