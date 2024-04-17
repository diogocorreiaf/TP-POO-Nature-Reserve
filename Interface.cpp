//
// Created by rodri on 23-11-2022.
//
#include "Interface.h"
#include "Utils.h"
#include "Storage.h"

Interface::Interface() {
    beginX = 0;
    beginY = 0;
    rows = 16;
    cols = 16;
    storage = nullptr;
}

string Interface::pedirComando(string &command) {
    cout << "Insira o comando: ";
    getline(cin, command);
    return command;
}

int Interface::identificaPrimeiraPalavraComando(const string &command) {
    vector<string> result;
    int totalargumentos, retornofunc = 0;
    result = split(command);

    totalargumentos = result.size();
//    cout << "Numero de argumentos do command: " << totalargumentos << endl;

    if (result[0] == "animal") {
        retornofunc = validaComandoCriarAnimal(command, totalargumentos);
    } else if (result[0] == "kill" || result[0] == "killid") {
        retornofunc = validaComandoMatarAnimal(command, totalargumentos);
    } else if (result[0] == "food") {
        retornofunc = validaComandoColocarAlimento(command, totalargumentos);
    } else if (result[0] == "feed" || result[0] == "feedid") {
        retornofunc = validaComandoAlimentarDiretamenteAnimal(command, totalargumentos);
    } else if (result[0] == "nofood") {
        retornofunc = validaComandoRemoverAlimento(command, totalargumentos);
    } else if (result[0] == "empty") {
        retornofunc = validaComandoEliminarNaPos(command, totalargumentos);
    } else if (result[0] == "see") {
        retornofunc = validaVerNaPos(command, totalargumentos);
    } else if (result[0] == "info") {
        retornofunc = validaVerInforElemento(command, totalargumentos);
    } else if (result[0] == "n") {
        retornofunc = validaAvancarInstante(command, totalargumentos);
    } else if (result[0] == "anim") {
        retornofunc = validaListarIDAnimais(command, totalargumentos);
    } else if (result[0] == "visanim") {
        retornofunc = validaListarIDAnimaisAreaVisivel(command, totalargumentos);
    } else if (result[0] == "store") {
        retornofunc = validaArmazenarReservaMemoria(command, totalargumentos);
    } else if (result[0] == "restore") {
        retornofunc = validaReativarEstadoGuardado(command, totalargumentos);
    } else if (result[0] == "load") {
        if (totalargumentos == 2) {
            cout << "[CMD: Executar Comandos de um Ficheiro de Texto] - Comando reconhecido e validado!";
            retornofunc = lerExecutarFicheiroComandos(result[1]);
        } else {
            cout << "[CMD: Executar Comandos de um Ficheiro de Texto] - Erro no numero de argumentos!";
            retornofunc = 0;
        }
    } else if (result[0] == "slide") {
        retornofunc = validaDeslocarAreaVisualizacao(command, totalargumentos);
    } else if (result[0] == "exit") {
        retornofunc = validaEncerrarSimulador(command, totalargumentos);
    } else {
        cout << "[CMD: Comando nao reconhecido]" << endl;
    }
    return retornofunc;
}


int Interface::validaComandoCriarAnimal(const string &command, const int &numarguments) {
    vector<string> result;
    bool verifica;
    int instant = 0;

    result = split(command);
    if (numarguments == 4) {
        if (!Utils::isNumber(result[2]) || !Utils::isNumber(result[3])) {
            cout
                    << "[CMD: Criar Animal] - Erro no terceiro ou quarto argumento! Para ambos tera que inserir um valor numerico"
                    << endl;
            return 0;
        } else {
            cout << "[CMD: Criar Animal] - Comando reconhecido e validado" << endl;
            int r = stoi(result[2]);
            int c = stoi(result[3]);
            instant = storage->getInstant();
            verifica = storage->addAnimal(result[1][0],instant, c, r);
            if (!verifica)
                cout << "[CMD: Criar Animal] - Erro na criacao do animal" << endl;
            return 0;
        }

    } else if (numarguments == 2) {
        instant = storage->getInstant();
        verifica = storage->addAnimal(result[1][0],instant);

        if (!verifica)
            cout << "[CMD: Criar Animal] - Erro na criacao do animal" << endl;
        return 0;

    } else {
        cout << "[CMD: Criar Animal] - Numero de argumentos invalido!" << endl;
        return 0;
    }
}

int Interface::validaComandoMatarAnimal(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    int x = 0, y = 0;

    if (result[0] == "kill") {
        if (numarguments == 3) {
            if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2])) {
                cout
                        << "[CMD: Matar Animal] - Erro no segundou ou terceiro argumentos! Tera que inserir um valor numerico"
                        << endl;
                return 0;
            } else {
                cout << "[CMD: Matar Animal] - Comando reconhecido e validado" << endl;
                y = stoi(result[1]);
                x = stoi(result[2]);

                storage->matarAnimals(y,x);

                return 0;
            }
        } else {
            cout << "[CMD: Matar Animal] - Numero de argumentos invalido!" << endl;
            return 0;
        }
    } else if (result[0] == "killid") {
        if (numarguments == 2) {
            if (!Utils::isNumber(result[1])) {
                cout << "[CMD: Matar Animal] - Erro no segundou argumento! Tera que inserir um valor numerico" << endl;
                return 0;
            } else {
                cout << "[CMD: Matar Animal] - Comando reconhecido e validado" << endl;
                return 0;
            }

        } else {
            cout << "[CMD: Matar Animal] - Numero de argumentos invalido!" << endl;
            return 0;
        }
    }

    return 0;
}

int Interface::validaComandoColocarAlimento(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    bool verifica;
    int nP = rand() % 10 + 1;
    int tP = rand() % 10 + 1;
    int lS = rand() % 15 + 1;

    if (numarguments == 4) {
        if (result[1] == "p") {
            cout << "[CMD: Colocar Alimento] - Erro no segundo argumento! Tera que inserir uma letra - r, t, b, a.\n";
            return 0;
        } else if (!Utils::isNumber(result[2]) || !Utils::isNumber(result[3])) {
            cout << "[CMD: Colocar Alimento] - Erro no segundo terceiro ou quarto! Tera que inserir um valor numerico"
                 << endl;
            return 0;
        } else {
            cout << "[CMD: Colocar Alimento] - Comando reconhecido e validado" << endl;
            int r = stoi(result[2]);
            int c = stoi(result[3]);
            verifica = storage->addFood(result[1][0], c, r);
            if (!verifica)
                cout << "Erro na criacao do alimento" << endl;
            return 0;
        }
    } else if (numarguments == 2) {
        if (result[1] == "p") {
            cout << "[CMD: Colocar Alimento] - Erro no segundo argumento! Tera que inserir uma letra - r, t, b, a.\n";
            return 0;
        } else {
            cout << "[CMD: Colocar Alimento] - Comando reconhecido e validado" << endl;
            verifica = storage->addFood(result[1][0]);
            if (!verifica)
                cout << "Erro na criacao do alimento" << endl;
            return 0;
        }
    } else {
        cout << "[CMD: Colocar Alimento] - Numero de argumentos invalido!" << endl;
        return 0;
    }

    return 0;
}

int Interface::validaComandoAlimentarDiretamenteAnimal(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    Animal *auxAnimal;
    int x = 0, y = 0;
    int nP = 0, nT = 0;
    int id = 0;

    if (result[0] == "feed") {
        if (numarguments == 5) {
            if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2]) || !Utils::isNumber(result[3]) ||
                !Utils::isNumber(result[4])) {
                cout
                        << "[CMD: Alimentar Diretamente Animal] - Erro num dos argumentos excepto o primeiro! Tera que inserir um valor numerico"
                        << endl;
                return 0;
            } else {
                cout << "[CMD: Alimentar Diretamente Animal] - Comando reconhecido e validado" << endl;
                //guardar variaveis
                y = stoi(result[1]);
                x = stoi(result[2]);
                nP = stoi(result[3]);
                nT = stoi(result[4]);

                storage->alimentaAnimais(y, x, nP, nT);

                return 0;
            }
        } else {
            cout << "[CMD: Alimentar Diretamente Animal] - Numero de argumentos invalido!" << endl;
            return 0;
        }
    } else if (result[0] == "feedid") {
        if (numarguments == 4) {
            if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2]) || !Utils::isNumber(result[3])) {
                cout
                        << "[CMD: Alimentar Diretamente Animal] - Erro no segundou, terceiro ou quarto argumentos! Tera que inserir um valor numerico"
                        << endl;
                return 0;
            } else {

                cout << "[CMD: Alimentar Diretamente Animal] - Comando reconhecido e validado" << endl;
                id = stoi(result[1]);
                nP = stoi(result[2]);
                nT = stoi(result[3]);

                if (storage->alimentaAnimal(id, nP, nT))
                    cout << "[CMD: Aliemtar Diretamente Animal] - Animal alimentado" << endl;
                else
                    cout << "[CMD: Aliemtar Diretamente Animal] - Animal nao encontrado" << endl;

                return 0;
            }

        } else {
            cout << "[CMD: Alimentar Diretamente Animal] - Numero de argumentos invalido!" << endl;
            return 0;
        }
    }

    return 0;
}

int Interface::validaComandoRemoverAlimento(const string &command, const int &numarguments) {
    int x = 0, y = 0, id = 0;
    bool remove;
    vector<string> result;
    result = split(command);

    if (numarguments == 3) {
        if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2])) {
            cout
                    << "[CMD: Remover Alimento] - Erro no segundo ou primeiro argumentos! Tera que inserir um valor numerico."
                    << endl;
            return 0;
        } else {
            cout << "[CMD: Remover Alimento] - Comando reconhecido e validado" << endl;
            x = stoi(result[2]);
            y = stoi(result[1]);

            remove = storage->destroyAlimento(y, x);
            if (!remove)
                cout << "Nao existe alimento na posicao" << endl;
            else
                cout << "Alimento removido com sucesso" << endl;
            return 0;
        }
    } else if (numarguments == 2) {
        if (!Utils::isNumber(result[1])) {
            cout << "[CMD: Remover Alimento] - Erro no segundo argumento! Tera que inserir um valor numerico." << endl;
            return 0;
        } else {
            cout << "[CMD: Remover Alimento] - Comando reconhecido e validado" << endl;
            id = stoi(result[1]);
            remove = storage->destroyAlimento(id);
            if (!remove)
                cout << "Nao existe alimento na posicao" << endl;
            else
                cout << "Alimento removido com sucesso" << endl;

            return 0;
        }
    } else {
        cout << "[CMD: Remover Alimento] - Numero de argumentos invalido!" << endl;
        return 0;
    }
}

int Interface::validaComandoEliminarNaPos(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    int x = 0, y = 0;
    bool remove;


    if (numarguments == 3) {
        if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2])) {
            cout
                    << "[CMD: Eliminar Na Posicao] - Erro no segundou ou terceiro argumentos! Tera que inserir um valor numerico"
                    << endl;
            return 0;
        } else {
            cout << "[CMD: Eliminar Na Posicao] - Comando reconhecido e validado" << endl;
            x = stoi(result[2]);
            y = stoi(result[1]);

            remove = storage->destroyAlimento(y, x);
            if (!remove)
                cout << "Nao existe alimento na posicao" << endl;
            else
                cout << "Alimento removido com sucesso" << endl;

            remove = storage->destroyAnimals(y, x);
            if (!remove)
                cout << "Nao existem animais na posicao" << endl;
            else
                cout << "Animais removidos com sucesso" << endl;

            return 0;
        }
    } else {
        cout << "[CMD: Eliminar Na Posicao] - Numero de argumentos invalido!" << endl;
        return 0;
    }
}

int Interface::validaVerNaPos(const string &command, const int &numarguments) {
    vector<string> result;
    vector<Animal *> animalsOnPosition;
    vector<Food *> foodsOnPosition;
    result = split(command);
    int row, col;

    if (numarguments == 3) {
        if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2])) {
            cout
                    << "[CMD: Ver Na Posicao] - Erro no segundou ou terceiro argumentos! Tera que inserir um valor numerico."
                    << endl;
            return 0;
        } else {

            row = stoi(result[1]);
            col = stoi(result[2]);
            cout << "[CMD: Ver Na Posicao] - Comando reconhecido e validado!" << endl;
            animalsOnPosition = storage->percorreAnimalLC(row, col);
            foodsOnPosition = storage->percorreAlimentoLC(row, col);

            if (animalsOnPosition.empty() && foodsOnPosition.empty())
                cout << "Posicao vazia, sem animal nem alimento!" << endl;
            else if (foodsOnPosition.empty() && !animalsOnPosition.empty()) {
                for (Animal *animal: animalsOnPosition) {
                    cout << animal->getAnimalAsString() << endl;
                }
            } else if (!foodsOnPosition.empty() && animalsOnPosition.empty()) {
                for (Food *food: foodsOnPosition) {
                    cout << food->getFoodAsString() << endl;
                }
            }
            return 0;
        }
    } else {
        cout << "[CMD: Ver Na Posicao] - Numero de argumentos invalido!" << endl;
        return 0;
    }
}

int Interface::validaVerInforElemento(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    int i;
    Animal *p = nullptr;
    Food *food = nullptr;

    if (numarguments == 2) {
        if (!Utils::isNumber(result[1])) {
            cout
                    << "[CMD: Ver Informacao Sobre Elemento] - Erro no segundo argumento! Tera que inserir um valor numerico!"
                    << endl;
            return 0;
        }
        i = stoi(result[1]);
        cout << "[CMD: Ver Informacao Sobre Elemento] - Comando reconhecido e validado!" << endl;
        p = storage->percorreAnimalId(i);
        if (p == nullptr) {
            food = storage->percorreAlimentoId(i);
            if (food == nullptr)
                cout << "Nao existe animal ou alimento com esse ID" << endl;
            else
                cout << food->getFoodAsString();
        } else
            cout << p->getAnimalAsString();
        return 0;

    } else {
        cout << "[CMD: Ver Informacao Sobre Elemento] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaAvancarInstante(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);

    if (numarguments == 1) {
        cout << "[CMD: Avancar Instante] - Comando reconhecido e validado" << endl;
        return 0;
    } else if (numarguments == 2) {
        if (!Utils::isNumber(result[1])) {
            cout << "[CMD: Avancar Instante] - Erro no segundo argumento! Tera que inserir um valor numerico" << endl;
            return 0;

        } else {
            cout << "[CMD: Avancar Instante] - Comando reconhecido e validado!" << endl;
            return 0;
        }

    } else if (numarguments == 3) {
        if (!Utils::isNumber(result[1]) || !Utils::isNumber(result[2])) {
            cout
                    << "[CMD: Avancar Instante] - Erro no segundo ou terceiro argumentos! Tera que inserir um valor numerico."
                    << endl;
            return 0;
        } else {
            cout << "[CMD: Avancar Instante] - Comando reconhecido e validado!" << endl;

            return 0;
        }
    } else {
        cout << "[CMD: Avancar Instante] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaListarIDAnimais(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    vector<Animal *> animals;

    if (numarguments == 1) {
        cout << "[CMD: Listar ID dos Animais] - Comando reconhecido e validado!" << endl;
        animals = storage->percorreAnimalLC();
        if (animals.empty()) {
            cout << "Nao Existem animais na storage" << endl;
            return 0;
        } else {
            for (Animal *animal: animals)
                cout << animal->getAnimalAsString() << endl;
            return 0;
        }
    } else {
        cout << "[CMD: Listar ID dos Animais] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaListarIDAnimaisAreaVisivel(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    vector<Animal *> animals;
    if (numarguments == 1) {
        cout << "[CMD: Listar ID dos Animais na Area Visisel] - Comando reconhecido e validado!" << endl;
        animals = storage->percorreAnimalLC(beginY, beginX, cols, rows);
        if (animals.empty()) {
            cout << "Nao Existem animais na area visivel" << endl;
            return 0;
        } else {
            for (Animal *animal: animals)
                cout << animal->getAnimalAsString() << endl;
            return 0;
        }
    } else {
        cout << "[CMD: Listar ID dos Animais na Area Visisel] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaArmazenarReservaMemoria(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);

    if (numarguments == 2) {
        cout << "[CMD: Armazenar Estado da Reserva em Memoria] - Comando reconhecido e validado!" << endl;

        if (storage->store(result[1]))
            cout << "[CMD: Armazenar Estado da Reserva em Memoria] - Reserva guardada" << endl;
        else
            cout << "[CMD: Armazenar Estado da Reserva em Memoria] - Ja existe uma reserva guardada com este nome!" << endl;

        return 0;
    } else {
        cout << "[CMD: Armazenar Estado da Reserva em Memoria] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaReativarEstadoGuardado(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);

    if (numarguments == 2) {
        cout << "[CMD: Reativar Estado Previamente Guardado] - Comando reconhecido e validado!" << endl;
        if (storage->store(result[1]))
            cout << "[CMD: Reativar Estado Previamente Guardado] -Restauraçao da reserva" << endl;
        else
            cout << "[CMD: Reativar Estado Previamente Guardado] -Nao existe uma reserva com esse nome" << endl;
            return 0;
    } else {
        cout << "[CMD: Reativar Estado Previamente Guardado] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}

int Interface::validaDeslocarAreaVisualizacao(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);
    int amount;

    if (numarguments != 3) {
        cout << "[CMD: Deslocar Area de Visualizacao] - Erro no numero de argumentos!" << endl;
        return 0;
    }

    if (!Utils::isNumber(result[2])) {
        cout << "[CMD: Deslocar Area de Visualizacao] - Erro no terceiro argumento!" << endl;
        return 0;
    }

    amount = stoi(result[2]);

    if (result[1] == "up") {
        if (beginY > amount)
            beginY -= amount;
    } else if (result[1] == "down") {
        if (beginY < storage->getMaxRows() - rows - amount)
            beginY += amount;
    } else if (result[1] == "left") {
        if (beginX > amount)
            beginX -= amount;
    } else if (result[1] == "right") {
        if (beginX < storage->getMaxCols() - cols - amount)
            beginX += amount;
    } else {
        cout << "[CMD: Deslocar Area de Visualizacao] - Erro no segundo argumento!" << endl;
        return 0;
    }

    cout << "[CMD: Deslocar Area de Visualizacao] - Comando reconhecido e validado!" << endl;
    return 0;
}

int Interface::validaEncerrarSimulador(const string &command, const int &numarguments) {
    vector<string> result;
    result = split(command);

    if (numarguments == 1) {
        cout << "[CMD: Encerrar Simulador] - Comando reconhecido e validado!" << endl;
        return 1;
    } else {
        cout << "[CMD: Encerrar Simulador] - Erro no numero de argumentos!" << endl;
        return 0;
    }
}


int Interface::lerExecutarFicheiroComandos(const string &filenamecoms) {
    ifstream ifs;
    ifs.open(filenamecoms);
    string command;

    while (getline(ifs, command)) {
        commandsvector.push_back(command);
        cout << "Comando do Ficheiro: " << command << endl;
        identificaPrimeiraPalavraComando(command);
    }
    ifs.close();

    return 0;
}


int Interface::lerExecutarFicheiroConstantes() {
    ifstream ifs;
    ifs.open("constantes.txt");

    string c;
    while (getline(ifs, c)) {
        constantsvector.push_back(c);
        cout << "Valor Constante: " << c << endl;
    }
    ifs.close();

    return 0;
}

int Interface::showViewArea() const {
    vector<vector<char>> viewarea = storage->getViewArea(beginY, beginX, rows, cols);

    for (int i = 0; i < min(rows, storage->getMaxRows()); ++i) {
        for (int j = 0; j < min(cols, storage->getMaxCols()); ++j) {
            cout << viewarea[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void Interface::jogar() {
    int flag = 0;
    string command;

    criaReserva();

    lerExecutarFicheiroConstantes();
    do {
        command = pedirComando(command);
        flag = identificaPrimeiraPalavraComando(command);
        showViewArea();
    } while (flag != 1);


}

vector<string> Interface::split(const string &command) {
    vector<string> result;
    istringstream iss(command);
    string s;

    if (command.empty()) {
        result.push_back("");
        return result;
    }

    while (getline(iss, s, ' ')) {
        result.push_back(s);
    }

    return result;
}

void Interface::criaReserva() {
    int row = 0, cols = 0;


    do {
        cout << "\nInsira numero de linhas: ";
        cin >> row;
    } while (row < 16 || row > 500);

    do {
        cout << "\nInsira numero de colunas: ";
        cin >> cols;
    } while (cols < 16 || cols > 500);

    storage = new Storage(row, cols);

}

// "  aid fa"

// start = 6
// end = 4























