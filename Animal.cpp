//
// Created by rodri on 23-11-2022.
//

#include "Coelho.h"
#include "Ovelha.h"
#include "Lobo.h"
#include "Canguru.h"
#include "Animal.h"
#include "Utils.h"


Animal::Animal(int i, int w, int hp, int lS, int x, int y,
               int m, int hMs1, int hMs2, int bC, int bD, int bI, int sR) {
    id = i;
    weight = w;
    health = hp;
    hunger = 0;
    lifeSpan = lS;
    row = y;
    col = x;
    metabolism = m;
    hungryMs1 = hMs1;
    hungryMs2 = hMs2;
    birthCicle = bC;
    birthDist = bD;
    birthInstant = bI;
    smelling_range=sR;

}

string Animal::getAnimalAsString() const {
    ostringstream oss;

    oss << "ID do Animal: " << id << endl;
    oss << "Especie do Animal: " << getName() << endl;
    oss << "Saude: " << health << endl;

    return oss.str();
}

Animal::~Animal() {
    history.clear();
}

int Animal::getId() const {
    return id;
}

int Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(int w) {
    weight = w;
}

int Animal::getHealth() const {
    return health;
}

void Animal::setHealth(int h) {
    health = h;
}

int Animal::getHunger() const {
    return hunger;
}

void Animal::setHunger(int h) {
    Animal::hunger = h;
}

int Animal::getLifeSpan() const {
    return lifeSpan;
}

void Animal::setLifeSpan(int l) {
    lifeSpan = l;
}

int Animal::getCol() const {
    return col;
}

void Animal::setCol(int c) {
    col = c;
}

int Animal::getRow() const {
    return row;
}

void Animal::setRow(int r) {
    row = r;
}

/*vector<Food*> Animal::getHistory() const {
    return history;
}*/

vector<string> Animal::getHistory() const {
    return history;
}

void Animal::addHistory(const string& alimento) {
    this->history.push_back(alimento);
}


/*void Animal::setHistory(const vector<Food *> &history) {
    for (Food* food : history)
        this->history.push_back(food->duplicate());
}*/

Animal *Animal::fabrica(char type, int id, int x, int y, int hp, int instant) {
    if (type == Coelho::LETTER){

        return new Coelho(id, x, y, instant);
    }
    if (type == Ovelha::LETTER) {
        if (hp == 0)
            return (Animal *) new Ovelha(id, x, y, instant);
        else
            return (Animal *) new Ovelha(id, x, y, instant,hp);
    }
    if (type == Lobo::LETTER)
        return new Lobo(id, x, y, instant);
    if (type == Canguru::LETTER)
        return new Canguru(id, x, y, instant);
    else return nullptr;
}

void Animal::come(int nP, int nT, const string& nome) {
    nP += getHealth();
    nP -= nT;
    setHealth(nP);
    addHistory("user");
}

int Animal::getBirthInstant() const {
    return birthInstant;
}

void Animal::setBirthInstant(int birthInstant) {
    Animal::birthInstant = birthInstant;
}



