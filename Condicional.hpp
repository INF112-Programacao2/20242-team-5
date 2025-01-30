#ifndef CONDICIONAL_HPP
#define CONDICIONAL_HPP

#include "Golpe.hpp"

class Condicional : public Golpe{ // Uma espécie de golpes que aplicam uma condição ao inimigo
    private:
        int _condicao; // 0 = nenhum, 1 = queimadura, 2 = paralisia ou 3 = veneno
        int _chance; // Chance da condição ser aplicada
        
    public:
        Condicional(); // Construtor
        int get_condicao();
        int get_chance();

        void set_condicao(int condicao);
        void set_chance(int chance);
};

#endif