#include "Condicional.hpp"

Condicional::Condicional() {} // Construtor

int Condicional::get_condicao(){
    return _condicao;
}

void Condicional::set_condicao(int condicao){
    _condicao = condicao;
}

int Condicional::get_chance(){
    return _chance;
}

void Condicional::set_chance(int chance){
    _chance = chance;
}