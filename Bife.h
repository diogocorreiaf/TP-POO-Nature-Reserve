//
// Created by Diogo on 15/12/2022.
//

#ifndef FOOD_CPP_BIFE_H
#define FOOD_CPP_BIFE_H


#include "Food.h"

class Bife : public Food {
    const static string NAME;
    const static int LIFESPAN = 30;
    const static int NUTRIPOINTS = 10;
    const static int TOXICPOINTS = 2;
    const static vector<string> SMELLS;

public:
    const static char LETTER = 'b';
    Bife(int id, int x, int y);
    Bife(const Bife& other);

    const string& getName() const override;
    const char getLetter() const override;
    const vector<string> &getSmells() const override;

    Food* duplicate() const override;
};


#endif //FOOD_CPP_BIFE_H
