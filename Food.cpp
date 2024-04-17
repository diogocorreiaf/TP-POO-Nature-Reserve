//
// Created by rodri on 23-11-2022.
//

#include "Food.h"
#include "Relva.h"
#include "Cenoura.h"
#include "Corpo.h"
#include "Bife.h"

Food::Food(int i, int x, int y, int nP, int tP) : row(y), col(x) {
    id = i;
    nutriPoints = nP;
    toxicPoints = tP;
    existent = true;
}

Food::~Food() {
    smells.clear();
}


string Food::getFoodAsString() const {
    ostringstream oss;

    oss << "ID do Alimento: " << id << endl;
    oss << "Alimento: " << name << endl;
    oss << "Letra representativa: " << letter << endl;

    return oss.str();
}

int Food::getId() const {
    return id;
}

int Food::getNutriPoints() const {
    return nutriPoints;
}

void Food::setNutriPoints(int nP) {
    nutriPoints = nP;
}

int Food::getToxicPoints() const {
    return toxicPoints;
}

void Food::setToxicPoints(int tP) {
    toxicPoints = tP;
}

const int Food::getCol() const {
    return col;
}

const int Food::getRow() const {
    return row;
}

Food *Food::fabrica(char type, int id, int x, int y, int nutriPoints, int toxicPoints) {
    if (type == Relva::LETTER)
        return new Relva(id, x, y);
    if (type == Cenoura::LETTER)
        return new Cenoura(id, x, y);
    if (type == Corpo::LETTER)
        return new Corpo(id, x, y, nutriPoints, toxicPoints);
    if (type == Bife::LETTER)
        return new Bife(id, x, y);
    else return nullptr;
}

bool Food::exists() const {
    return existent;
}

void Food::kill() {
    existent = false;
}


