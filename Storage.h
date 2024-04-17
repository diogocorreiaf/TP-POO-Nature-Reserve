//
// Created by Diogo on 02/01/2023.
//

#ifndef FOOD_CPP_STORAGE_H
#define FOOD_CPP_STORAGE_H

#include <vector>
#include <string>

using namespace std;

class Reserva;

class Food;

class Animal;

class Item {
    string name;
    Reserva* reserva;

public:
    Item(const string& n, Reserva* r);
    ~Item();

    string getName() const;
    Reserva* getReserva() const;
};

class Storage {
    vector<Item *> items;
    Reserva *current;

    Reserva *getReserva(const string &nome);

public:
    Storage(int maxR, int maxC);

    ~Storage();


    bool store(const string &name);

    bool restore(const string &name);

    int getMaxRows() const;

    int getMaxCols() const;

    int getInstant() const;

    void setInstant(int instant);


    bool addAnimal(char letter, int instant, int x = -1, int y = -1, int hp = 0);

    bool addFood(char letter, int x = -1, int y = -1, int nP = 0, int tP = 0);

    void alimentaAnimais(int row, int col, int nP, int nT) const;

    bool alimentaAnimal(int id, int nP, int nT) const;

    bool destroyAlimento(int Id);//percorre o vetor dos alimentos e elimina da posiçao do vetor
    bool destroyAlimento(int row, int col);

    bool destroyAnimals(int row, int col);
    bool matarAnimals(int row, int col);

    vector<Food *> percorreAlimentoLC(int row, int col); //função para percorrer alimentos por linha coluna
    Food *percorreAlimentoId(int id);//função para percorrer alimentos por ID

    vector<Animal *> percorreAnimalLC(int row = -1, int col = -1) const;  //função para percorrer animais por linha coluna
    vector<Animal *> percorreAnimalLC(int row, int col, int maxrows, int maxcols) const;
    Animal *percorreAnimalId(int Id) const;

    vector<vector<char>> getViewArea(int startR, int startC, int rows, int cols) const;
};

#endif //FOOD_CPP_STORAGE_H
