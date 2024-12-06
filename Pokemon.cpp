#include "Pokemon.hpp"

Pokemon::Pokemon(int id, std::string nome, int vida, int ataque, int defesa, int ataqueEspecial, int defesaEspecial, int velocidade, Tipo &tipo1, Tipo &tipo2) : _id(id), _nome(nome), _tipo1(tipo1), _tipo2(tipo2) {
    _estatisticas[0] = vida;
    _estatisticas[1] = ataque;
    _estatisticas[2] = defesa;
    _estatisticas[3] = ataqueEspecial;
    _estatisticas[4] = defesaEspecial;
    _estatisticas[5] = velocidade;
}

int Pokemon::get_id(){
    return _id;
}

std::string Pokemon::get_nome() {
    return _nome;
}

int Pokemon::get_estatistica(int estatistica){
    return _estatisticas[estatistica];
}
