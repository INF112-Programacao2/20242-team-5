#ifndef TIPO_H
#define TIPO_H

#include <string>

class Tipo{
    private:
        std::string _nome;
        int _numRep; // Número que irá representar o tipo
        int _relacoes[18]; // Relação que cada tipo tem com os 18 tipos na seguinte ordem: 0 = Normal, 1 = Fogo, 2 = Água, 3 = Grama, 4 = Elétrico, 5 = Gelo, 6 = Fighting, 7 = Veneno, 8 = Solo, 9 = Voador, 10 = Psíquico, 11 = Inseto, 12 = Pedra, 13 = Fantasma, 14 = Dragão, 15 = Escuridão, 16 = Aço, 17 = Fada;
    public:
        Tipo(std::string nome, int numRep, int relacoes[]); // Construtor
        std::string get_nome();
        int get_numRep();
        int get_relacoes(int tipo);
};

#endif