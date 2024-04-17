//
// Created by rodri on 23-11-2022.
//

#ifndef TP2223_INTERFACE_H
#define TP2223_INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstring>
#include "Food.h"
#include "Animal.h"

using namespace std;

class Reserva;
class Storage;

class Interface{
public:
    Interface();

    int identificaPrimeiraPalavraComando(const string& command);

    int validaComandoCriarAnimal(const string &command, const int &numarguments);

    int validaComandoMatarAnimal(const string &command, const int &numarguments);

    int validaComandoColocarAlimento(const string &command, const int &numarguments);

    int validaComandoAlimentarDiretamenteAnimal(const string &command, const int &numarguments);

    int validaComandoRemoverAlimento(const string &command, const int &numarguments);

    int validaComandoEliminarNaPos(const string &command, const int &numarguments);

    int validaVerNaPos(const string &command, const int &numarguments);

    int validaVerInforElemento(const string &command, const int &numarguments);

    int validaAvancarInstante(const string &command, const int &numarguments);

    int validaListarIDAnimais(const string &command, const int &numarguments);

    int validaListarIDAnimaisAreaVisivel(const string &command, const int &numarguments);

    int validaArmazenarReservaMemoria(const string &command, const int &numarguments);

    int validaReativarEstadoGuardado(const string &command, const int &numarguments);

    int validaDeslocarAreaVisualizacao(const string &command, const int &numarguments);

    int validaEncerrarSimulador(const string &command, const int &numarguments);

    int lerExecutarFicheiroComandos(const string &filenamecoms);

    int lerExecutarFicheiroConstantes();

    int showViewArea() const;
    string pedirComando(string& command);

    void jogar();
    void criaReserva();
private:
    vector<string> commandsvector;
    vector<string> constantsvector;
    //string filenamecoms, filenameconst;
    vector<string> split (const string& command);
    //int numarguments;
    Storage* storage;
    int beginX;
    int beginY;
    int cols;
    int rows;
    //Animal a
    //Food f;
};


#endif //TP2223_INTERFACE_H
