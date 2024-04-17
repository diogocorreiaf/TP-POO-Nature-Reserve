//
// Created by rodri on 23-11-2022.
//

#ifndef TP2223_ANIMAL_H
#define TP2223_ANIMAL_H

#include "headers.h"
#include "Food.h"

class Animal {

public:
    Animal(int i, int w, int hp, int lS, int x, int y,
           int m, int hMs1, int hMs2, int bS, int bD, int bI, int sR);

    virtual ~Animal();

    string getAnimalAsString() const;

    int getId() const;

    virtual const string &getName() const = 0;

    virtual const char getLetter() const = 0;

    int getWeight() const;
    void setWeight(int weight);

    int getHealth() const;
    void setHealth(int health);

    int getHunger() const;
    void setHunger(int hunger);

    int getLifeSpan() const;
    void setLifeSpan(int lifeSpan);

    int getCol() const;
    void setCol(int c);

    int getRow() const;
    void setRow(int row);

    //vector<Food*> getHistory() const;
    //void setHistory(const vector<Food*>& history);
   vector<string> getHistory() const;
   void addHistory(const string& alimento);

   void come(int nP, int nT, const string& nome);

    static Animal* fabrica(char type, int id, int x, int y, int hp, int instant);
    virtual Animal* duplicate() const = 0;

private:
    int id;
    char letter;
    int weight;
    int health;
    int hunger;
    int lifeSpan;
    //vector<Food *> history;
    vector<string> history;
    int col, row;
    int metabolism;
    int hungryMs1;
    int hungryMs2;
    int birthCicle;
    int birthDist;
    int birthInstant;
    int smelling_range;
public:
    int getBirthInstant() const;

    void setBirthInstant(int birthInstant);

};


#endif //TP2223_ANIMAL_H
