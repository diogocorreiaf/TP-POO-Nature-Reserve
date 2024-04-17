//
// Created by Diogo on 02/01/2023.
//

#include "Storage.h"
#include "Reserva.h"
#include "Food.h"
#include "Animal.h"

Item::Item(const string &n, Reserva *r) : name(n), reserva(new Reserva(*r)) {
}

Item::~Item() {
    delete reserva;
}

string Item::getName() const {
    return name;
}

Reserva *Item::getReserva() const {
    return reserva;
}

Storage::Storage(int maxR, int maxC) {
    current = new Reserva(maxR, maxC);
}

Storage::~Storage() {
    for (Item* item : items)
        delete item;
    items.clear();

    delete current;
}

bool Storage::store(const string &name) {
    if (getReserva(name) != nullptr)
        return false;
    items.push_back(new Item(name, current));
    return true;
}

bool Storage::restore(const string& name) {
    Reserva *reserva = getReserva(name);
    if (reserva == nullptr)
        return false;

    delete current;
    current = reserva;

    return true;
}

Reserva *Storage::getReserva(const string &nome) {
    for (Item *item : items)
        if (item->getName() == nome)
            return item->getReserva();

    return nullptr;
}

bool Storage::addAnimal(char letter, int instant, int x, int y, int hp) {
    return current->addAnimal(letter, x, y, instant, hp);
}

bool Storage::addFood(char letter, int x, int y, int nP, int tP) {
    return current->addFood(letter, x, y, nP, tP);
}

void Storage::alimentaAnimais(int row, int col, int nP, int nT) const {
    current->alimentaAnimais(row, col, nP, nT);
}

bool Storage::alimentaAnimal(int id, int nP, int nT) const {
    if(current->alimentaAnimal(id, nP, nT))
       return true;
    else
        return false;
}

bool Storage::destroyAnimals(int row, int col) {
    if(current->destroyAnimals(row, col))
        return true;
    else
        return false;
}

bool Storage::destroyAlimento(int Id) {
    if(current->destroyAlimento(Id))
        return true;
    else
        return false;
}

bool Storage::destroyAlimento(int row, int col) {
    if(current->destroyAlimento(row, col))
        return true;
    else
        return false;
}

vector<Food *> Storage::percorreAlimentoLC(int row, int col) {
    vector<Food *> aux;
    aux=current->percorreAlimentoLC(row,col);
    return aux;
}

Food *Storage::percorreAlimentoId(int id) {
    Food* aux;
    aux=current->percorreAlimentoId(id);
    return aux;
}

vector<Animal *> Storage::percorreAnimalLC(int row, int col) const{
    vector<Animal *> aux;
    aux=current->percorreAnimalLC(row,col);
    return aux;
}

vector<Animal *> Storage::percorreAnimalLC(int row, int col, int maxrows, int maxcols) const {
    vector<Animal *> aux;
    aux=current->percorreAnimalLC(row,col,maxrows,maxcols);
    return aux;
}

Animal *Storage::percorreAnimalId(int Id) const {
    Animal * aux;
    aux = current->percorreAnimalId(Id);
    return aux;
}

int Storage::getMaxRows() const {
    int aux;
    aux=current->getMaxRows();
    return aux;
}

int Storage::getMaxCols() const {
    int aux;
    aux=current->getMaxCols();
    return aux;
}

vector<vector<char>> Storage::getViewArea(int startR, int startC, int rows, int cols) const {
    vector<vector<char>> aux;
    aux = current->getViewArea(startR,startC,rows,cols);
    return aux;
}

int Storage::getInstant() const {
    return current->getInstant();
}

void Storage::setInstant(int instant) {
    current->setInstant(instant);
}

bool Storage::matarAnimals(int row, int col) {
    return current->matarAnimals();
}

