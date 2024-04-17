//
// Created by Diogo on 27/12/2022.
//

#ifndef FOOD_CPP_CORPO_H
#define FOOD_CPP_CORPO_H


#include "Food.h"

class Corpo : public Food {
    const static string NAME;
    const static int NUTRIPOINTSCYCLE = 1;
    const static int TOXICPOINTSCYCLE = 1;
    const static vector<string> SMELLS;
    const int MAXTOXICPOINTS;

public:
    const static char LETTER = 'p';
    Corpo(int id, int x, int y, int nutriPoints, int toxicPoints);
    Corpo(const Corpo& other);


    const string& getName() const override;
    const char getLetter() const override;
    const vector<string> &getSmells() const override;

    Food* duplicate() const override;


};


#endif //FOOD_CPP_CORPO_H
