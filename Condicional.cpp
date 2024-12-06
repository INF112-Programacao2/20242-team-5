#include "Condicional.hpp"

Condicional::Condicional(std::string nome, int poderBase, int precisao, Tipo &tipo, bool especial, int condicao, int chance) : Golpe(nome, poderBase, precisao, tipo, especial), _condicao(condicao), _chance(chance) {} // Construtor

int Condicional::get_condicao(){
    return _condicao;
}

int Condicional::get_chance(){
    return _chance;
}
