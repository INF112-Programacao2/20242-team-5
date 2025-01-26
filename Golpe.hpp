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
        Golpe(); // Construtor
        
        std::string get_nome();
        int get_poderBase();
        int get_precisao();
        Tipo get_tipo();
        int get_tipoNum();

        void set_nome(std::string nome);
        void set_poderBase(int poderBase);
        void set_precisao(int precisao);
        void set_tipo(Tipo tipo);
        void set_tipoNum(int tipoNum);
        void set_especial(bool especial);

        bool is_especial();
};

#endif
