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
        void set_nome(std::string nome);
        int get_poderBase();
        void set_poderBase(int poderBase);
        int get_precisao();
        void set_precisao(int precisao);
        Tipo get_tipo();
        void set_tipo(Tipo tipo);
        int get_tipoNum();
        void set_tipoNum(int tipoNum);
        bool is_especial();
        void set_especial(bool especial);
};

#endif
