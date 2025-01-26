#include "Golpe.hpp"

Golpe::Golpe() {} // Construtor

std::string Golpe::get_nome(){
    return _nome;
}

int Golpe::get_poderBase(){
    return _poderBase;
}

int Golpe::get_precisao(){
    return _precisao;
}

Tipo Golpe::get_tipo(){
    return _tipo;
}

int Golpe::get_tipoNum(){
    return _tipo.get_numRep();
}

void Golpe::set_nome(std::string nome){
    _nome = nome;
}

void Golpe::set_poderBase(int poderBase){
    _poderBase = poderBase;
}

void Golpe::set_precisao(int precisao){
    _precisao = precisao;
}

void Golpe::set_tipo(Tipo tipo){
    _tipo = tipo;
}

void Golpe::set_especial(bool especial){
    _especial = especial;
}

bool Golpe::is_especial(){
    return _especial;
}
