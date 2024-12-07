#include "Tipo.hpp"

Tipo::Tipo(std::string nome, int numRep, float relacoes[]): _nome(nome), _numRep(numRep) {
    for(int i = 0; i < 18; i++)
        _relacoes[i] = relacoes[i]; // Colocando todas as relações no tipo
}

int Tipo::get_numRep(){
    return _numRep;
}

float Tipo::get_relacao(int tipo){
    return _relacoes[tipo]; // Retornando a relação com o tipo desejado
}

float* Tipo::get_relacoes(){
    return _relacoes;
}