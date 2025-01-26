#include "Condicional.hpp"

Condicional::Condicional() {} // Construtor

int Condicional::get_condicao() const {
    return _condicao;
}

int Condicional::get_chance() const {
    return _chance;
}

void Condicional::set_condicao(int condicao){
    _condicao = condicao;
}

void Condicional::set_chance(int chance){
    _chance = chance;
}
