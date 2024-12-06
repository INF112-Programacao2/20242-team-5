#ifndef CONDICIONAL_HPP
#define CONDICIONAL_HPP

#include "Golpe.h"

class Condicional : public Golpe{ // Uma espécie de golpes que aplicam uma condição ao inimigo
    private:
        int _condicao; // 0 = nenhum, 1 = queimadura, 2 = congelamento, 3 = paralisia, 4 = veneno ou 5 = sono
        int _chance; // Chance da condição ser aplicada
    public:
        Condicional(std::string nome, int poderBase, int precisao, Tipo tipo, bool especial, int condicao, int chance); // Construtor
        int get_condicao();
        int get_chance();
};

#endif
