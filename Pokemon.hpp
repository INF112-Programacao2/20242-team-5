#ifndef Pokemon_HPP
#define Pokemon_HPP

#include <string>
#include "Estatisticas.hpp"

class Pokemon {
    private:
        int _id;
        std::string _nome;
        Estatisticas _estatisticas;

    public:
        Pokemon(int id, std::string nome);
        int get_id();
        std::string get_nome();

        int get_vida() const;
        int get_ataque() const;
        int get_defesa() const;
        int get_ataqueEspecial() const;
        int get_defesaEspecial() const;
        int get_velocidade() const;
};

#endif
