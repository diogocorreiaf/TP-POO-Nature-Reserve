//
// Created by rodri on 24-11-2022.
//

#ifndef TP2223_RESERVA_H
#define TP2223_RESERVA_H

#include "headers.h"
#include "Animal.h"
#include "Food.h"


class Reserva {
public:
    Reserva(int maxR, int maxC);

    Reserva(const Reserva &outro);

    ~Reserva();

    int getMaxRows() const;

    int getMaxCols() const;

    int getInstant() const;

    void setInstant(int instant);


    bool addAnimal(char letter, int instante, int x = -1, int y = -1, int hp = 0);//adiciona animais ao vetor
    bool addFood(char letter, int x = -1, int y = -1, int nP = 0, int tP = 0);

    vector<vector<char>> getViewArea(int startR, int startC, int rows, int cols) const; //Janela de visualizaçao
    vector<Animal *> percorreAnimalLC(int row = -1, int col = -1) const;  //função para percorrer animais por linha coluna
    vector<Animal *> percorreAnimalLC(int row, int col, int maxrows, int maxcols) const;

    Animal *percorreAnimalId(int Id) const;  //função para percorrer animais por id
    vector<Food *> percorreAlimentoLC(int row, int col); //função para percorrer alimentos por linha coluna
    Food *percorreAlimentoId(int id);//função para percorrer alimentos por ID

    void alimentaAnimais(int row, int col, int nP, int nT) const;
    bool alimentaAnimal(int id, int nP, int nT) const;

    bool destroyAlimento(int Id);//percorre o vetor dos alimentos e elimina da posiçao do vetor
    bool destroyAlimento(int row, int col);

    bool destroyAnimals(int row, int col);//Remove completamente o animal do vetor e chama o destrutor;
    bool matarAnimals(int row, int col);//mata o animal e cria o alimento de acordo com o tipo;

    vector<Animal *> returnAnimalsInRange(int smellRange, Animal &animal);//retorna um vetor com todos os animais dentro da area do animal em questao
    vector <Food*> returnFoodsInRange(int smellRange, Animal &animal);

    void limpa();

    vector<Animal *> procuraAnimaisRedondezas(int x, int y, int dist, char letter);

    vector<Food *> procuraAlimentosRedondezas(int x, int y, int dist, char letter);

private:
    vector<Animal *> animals;
    vector<Food *> foods;
    int idIt;
    int instant;
public:

private:
    int maxRows;
    int maxCols;
    //Animal a;
    //Food f;
};

#endif //TP2223_RESERVA_H
