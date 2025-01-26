#include "Tipo.hpp"

Tipo::Tipo() {}

std::string Tipo::get_nome(){
    return _nome;
}

void Tipo::set_nome(std::string nome){
    _nome = nome;
}

int Tipo::get_numRep(){
    return _numRep;
}

void Tipo::set_numRep(int numRep){
    _numRep = numRep;
}

float Tipo::get_relacao(int tipo1, int tipo2){
    return _relacoes[tipo1][tipo2]; // Retornando a relação com o tipo desejado
}

void Tipo::set_relacao(float valor, int tipo1, int tipo2){
    _relacoes[tipo1][tipo2] = valor;
}

float Tipo::_relacoes[19][19];