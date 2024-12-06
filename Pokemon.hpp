#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include "Tipos.cpp"

class Pokemon {
    private:
        int _id;
        std::string _nome;
        int _estatisticas[6];
        Tipo _tipo1;
        Tipo _tipo2;

    public:
        Pokemon(int id, std::string nome, int vida, int ataque, int defesa, int ataqueEspecial, int defesaEspecial, int velocidade, Tipo &tipo1, Tipo &tipo2);
        int get_id();
        std::string get_nome();
        int get_estatistica(int estatistica);
};

#endif
