#include "Tipo.hpp"

Tipo::Tipo() {}

std::string Tipo::get_nome(){
    return _nome;
}

int Tipo::get_numRep(){
    return _numRep;
}

float Tipo::get_relacao(int tipo1, int tipo2){
    return _relacoes[tipo1][tipo2]; // Retorna a relação entre dois tipos
}



void Tipo::set_nome(std::string nome){
    _nome = nome;
}

void Tipo::set_numRep(int numRep){
    _numRep = numRep;
}

void Tipo::set_relacao(float valor, int tipo1, int tipo2){
    _relacoes[tipo1][tipo2] = valor; // Coloca a relação entre dois tipos
}

float Tipo::_relacoes[18][18]; // Declaração da matriz
