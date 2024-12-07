#include "Golpe.hpp"

Golpe::Golpe(std::string nome, int poderBase, int precisao, Tipo &tipo, bool especial) : _nome(nome), _poderBase(poderBase), _precisao(precisao), _tipo(tipo), _especial(especial) {} // Construtor

std::string Golpe::get_nome(){
    return _nome;
}

int Golpe::get_poderBase(){
    return _poderBase;
}

int Golpe::get_precisao(){
    return _precisao;
}

int Golpe::get_tipoNum(){
    return _tipo.get_numRep();
}

Tipo Golpe::get_tipo(){
    return _tipo;
}

bool Golpe::is_especial(){
    return _especial;
}