#include "Golpe.hpp"

Golpe::Golpe(std::string nome, int poderBase, int precisao, Tipo &tipo, bool especial) : _nome(nome), _poderBase(poderBase), _precisao(precisao), _tipo(tipo), _especial(especial) {} // Construtor

std::string Golpe::get_nome(){
    return _nome;
}

void Golpe::set_nome(std::string nome){
    _nome = nome;
}

int Golpe::get_poderBase(){
    return _poderBase;
}

void Golpe::set_poderBase(int poderBase){
    _poderBase = poderBase;
}

int Golpe::get_precisao(){
    return _precisao;
}

void Golpe::set_precisao(int precisao){
    _precisao = precisao;
}

int Golpe::get_tipoNum(){
    return _tipo.get_numRep();
}

Tipo Golpe::get_tipo(){
    return _tipo;
}

void Golpe::set_tipo(Tipo tipo){
    _tipo = tipo;
}

bool Golpe::is_especial(){
    return _especial;
}

void Golpe::set_especial(bool especial){
    _especial = especial;
}