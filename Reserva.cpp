//
// Created by rodri on 24-11-2022.
//

#include "Reserva.h"

vector<vector<char>> Reserva::getViewArea(int startR, int startC, int rows, int cols) const {
    vector<vector<char>> viewArea;

    if (startR + rows >= maxRows)
        startR = maxRows - rows;
    if (startC + cols >= maxCols)
        startC = maxCols - cols;

    if (startR < 0)
        startR = 0;
    if (startC < 0)
        startC = 0;

    if (rows > maxRows)
        rows = maxRows;
    if (cols > maxCols)
        cols = maxCols;

    for (int i = 0; i < rows && i < maxRows - startR; i++) {
        viewArea.push_back(vector<char>());
        for (int j = 0; j < cols && j < maxCols - startC; j++)
            viewArea[i].push_back('_');
    }

    for (Animal *animal: animals)
        if (animal->getRow() >= startR && animal->getRow() < startR + rows &&
            animal->getCol() >= startC && animal->getCol() < startC + cols)
            viewArea[animal->getRow() - startR][animal->getCol() - startC] = animal->getLetter();

    for (Food *food: foods)
        if (food->getRow() >= startR && food->getRow() < startR + rows &&
            food->getCol() >= startC && food->getCol() < startC + cols)
            viewArea[food->getRow() - startR][food->getCol() - startC] = food->getLetter();

    return viewArea;
}

/*
 . . . . . . . . .
 . . +---2-------+
 . . | . . 1 . . |
 . . | . . . . . |
 . . +-----------+

 sR = 1
 sC = 2
 r = 4
 c = 7

 aR = 2
 aC = 5
 */

Reserva::Reserva(int maxR, int maxC) {
    maxRows = maxR;
    maxCols = maxC;
    idIt = 1;
    instant = 0;
}

Reserva::Reserva(const Reserva &outro) {
    this->idIt = outro.idIt;
    this->instant = outro.instant;
    this->maxRows = outro.maxRows;
    this->maxCols = outro.maxCols;

    for (Animal *animal: animals)
        this->animals.push_back(animal->duplicate());
    for (Food *food: foods)
        this->foods.push_back(food->duplicate());
}

bool Reserva::addAnimal(char letter, int instante, int x, int y, int hp) {
    if (x == -1)
        x = rand() % maxCols;
    if (y == -1)
        y = rand() % maxRows;

    if (hp < 0 || x < 0 || x >= maxCols || y < 0 || y >= maxRows)
        return false;

    Animal *animal = Animal::fabrica(letter, idIt++, x, y, hp,instante );
    if (animal == nullptr) {
        return false;
    }

    animals.push_back(animal);

    return true;
}

bool Reserva::addFood(char letter, int x, int y, int nP, int tP) {

    if (x == -1)
        x = rand() % maxCols;
    if (y == -1)
        y = rand() % maxRows;

    if ( nP < 0 || tP < 0 || x < 0 || x >= maxCols || y < 0 || y >= maxRows)
        return false;

    Food *food = Food::fabrica(letter, idIt++, x, y, nP, tP);
    if (food == nullptr)
        return false;
    foods.push_back(food);
    return true;
}

vector<Animal *> Reserva::percorreAnimalLC(int row, int col) const {
    vector<Animal *> animalLC;

    if (row != -1 && col != -1) {
        for (Animal *animal: animals) {
            if (animal->getCol() == col && animal->getRow() == row)
                animalLC.push_back(animal);
        }
    } else {
        for (Animal *animal: animals)
            animalLC.push_back(animal);
    }
    return animalLC;
}

vector<Animal *> Reserva::percorreAnimalLC(int row, int col, int maxrows, int maxcols) const {
    vector<Animal *> animalLC;
    for (Animal *animal: animals) {
        if (animal->getCol() >= col && animal->getCol() <= maxcols
            && animal->getRow() >= row && animal->getRow() <= maxrows)
            animalLC.push_back(animal);
    }

    return animalLC;
}


Animal *Reserva::percorreAnimalId(int Id) const {
    for (Animal *animal: animals) {
        if (animal->getId() == Id)
            return animal;
    }
    return nullptr;
}

vector<Food *> Reserva::percorreAlimentoLC(int row, int col) {
    vector<Food *> result;
    for (Food *food: foods)
        if (food->getRow() == row && food->getCol() == col)
            result.push_back(food);
    return result;
}


Food *Reserva::percorreAlimentoId(int id) {
    for (Food *food: foods)
        if (food->getId() == id)
            return food;
    return nullptr;
}

Reserva::~Reserva() {
    for (Animal *animal: animals)
        delete animal;
    animals.clear();

    for (Food *food: foods)
        delete food;
    foods.clear();
}

int Reserva::getMaxRows() const {
    return maxRows;
}

int Reserva::getMaxCols() const {
    return maxCols;
}

vector<Animal *> Reserva::procuraAnimaisRedondezas(int x, int y, int dist, char letter) {
    vector<Animal *> list;

    for (Animal *animal: animals) {
        if (animal->getLetter() == letter &&
            abs(x - animal->getCol()) <= dist &&
            abs(y - animal->getRow()) <= dist)
            list.push_back(animal);
    }

    return list;
}

void Reserva::limpa() {
    // Limpa animais
    for (int i = 0; i < animals.size();) {
        if (animals[i]->getHealth() <= 0){
            delete animals[i];
            animals.erase(animals.begin() + i);
        }

        else
            i++;
    }
    // Limpa alimentos
    for (int i = 0; i < foods.size();) {
        if (!foods[i]->exists()){
            delete foods[i];
            foods.erase(foods.begin() + i);
        }
        else
            i++;
    }
}

bool Reserva::destroyAlimento(int Id) {
    for (int i = 0; i < foods.size();) {
        if (foods[i]->getId() == Id) {
            delete foods[i];
            foods.erase(foods.begin() + i);
            return true;
        }
        i++;
    }
    return false;
}

bool Reserva::destroyAlimento(int row, int col) {
    for (int i = 0; i < foods.size();) {
        if (foods[i]->getRow() == row && foods[i]->getCol() == col) {
            delete foods[i];
            foods.erase(foods.begin() + i);
            return true;
        }
        i++;
    }
    return false;
}

bool Reserva::destroyAnimals(int row, int col) {
    int contador = 0;

    for (int i = 0; i < animals.size();) {
        if (animals[i]->getRow() == row && animals[i]->getCol() == col) {
            delete animals[i];
            animals.erase(animals.begin() + i);
            contador++;
        } else {
            i++;
        }
    }
    if (contador > 0)
        return true;
    return false;
}

void Reserva::alimentaAnimais(int row, int col, int nP, int nT) const {
    vector<Animal *> aux;

    aux = percorreAnimalLC(row, col);
    for (Animal *animal: aux) {
        animal->come(nP, nT, "user");
    }
}

bool Reserva::alimentaAnimal(int id, int nP, int nT) const {
    Animal *animal = percorreAnimalId(id);

    if (animal == nullptr)
        return false;

    animal->come(nP, nT, "user");
    return true;
}

int Reserva::getInstant() const {
    return instant;
}

void Reserva::setInstant(int instant) {
    Reserva::instant = instant;
}

bool Reserva::matarAnimals(int row, int col) {
    vector <Animal *> aux;
    aux = percorreAnimalLC(row,col);

    for (Animal *animal: animals){
        animal->setHealth(0);
        if(animal->getLetter() != 'c')
            //TODO colocar aqui os valores certos
            // talvez um const static int NutriPointsWhenDeath na classe
            addFood('p',animal->getRow()-1,animal->getCol()-1,15,0);
    }
    return true;
}


vector<Animal *> Reserva::returnAnimalsInRange(int smellRange, Animal &animal) {
    vector<Animal*> animalsInRange;
    int center_row = animal.getRow();
    int center_col = animal.getCol();

    for (int row = center_row - smellRange; row <= center_row + smellRange; row++) {
        for (int col = center_col - smellRange; col <= center_col + smellRange; col++) {
            for(Animal *ani : animals){
                if (ani->getRow() == row && ani->getCol() == col)
                    animalsInRange.push_back(ani);
            }
        }
    }
    return animalsInRange;
}

vector<Food *> Reserva::returnFoodsInRange(int smellRange, Animal &animal) {
    vector<Food*> foodsInRange;
    int center_row = animal.getRow();
    int center_col = animal.getCol();

    for (int row = center_row - smellRange; row <= center_row + smellRange; row++) {
        for (int col = center_col - smellRange; col <= center_col + smellRange; col++) {
            for(Food *fd : foods){
                if (fd->getRow() == row && fd->getCol() == col)
                    foodsInRange.push_back(fd);
            }
        }
    }

    return foodsInRange;
}

