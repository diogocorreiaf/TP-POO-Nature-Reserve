//
// Created by rodri on 23-11-2022.
//

#ifndef TP2223_FOOD_H
#define TP2223_FOOD_H

#include "headers.h"

class Food {

public:
    Food(int id, int x, int y, int nP, int tP);

    virtual ~Food();

    string getFoodAsString() const;

    int getId() const;

    virtual const char getLetter() const = 0;

    virtual const string &getName() const = 0;

    int getNutriPoints() const;
    void setNutriPoints(int nP);
    int getToxicPoints() const;
    void setToxicPoints(int tP);

    const int getCol() const;
    const int getRow() const;

    bool exists() const;
    void kill();

    virtual const vector<string> &getSmells() const = 0;

    static Food* fabrica(char type, int id, int x, int y, int nutriPoints, int toxicPoints);
    virtual Food* duplicate() const = 0;


private:
    int id;
    char letter;
    string name;
    int nutriPoints;
    int toxicPoints;
    const int col, row;
    vector<string> smells;

    bool existent;
};


#endif //TP2223_FOOD_H
