#ifndef GOLPE_HPP
#define GOLPE_HPP

#include "Tipo.hpp"
#include <string>

class Golpe{
    protected:
        std::string _nome; // Identificação do golpe
        int _poderBase; // Dano base do golpe
        int _precisao; // Chance do golpe acertar
        Tipo _tipo; // Tipo do golpe
        bool _especial; // Se é físico ou especial
    public:
        Golpe(std::string nome, int poderBase, int precisao, Tipo &tipo, bool especial); // Construtor
        std::string get_nome();
        int get_poderBase();
        int get_precisao();
        Tipo get_tipo();
        bool is_especial();
};

#endif
