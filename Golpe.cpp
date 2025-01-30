#include "Golpe.hpp"

Golpe::Golpe() {} // Construtor

std::string Golpe::get_nome(){
    return _nome;
}

int Golpe::get_id(){
    return _id;
}

int Golpe::get_poderBase(){
    return _poderBase;
}

int Golpe::get_precisao(){
    return _precisao;
}

int Golpe::get_tipoNum(){
    return _tipo.get_numRep(); // Retorna o número que representa o tipo
}

Tipo Golpe::get_tipo(){
    return _tipo;
}

bool Golpe::is_especial(){
    return _especial;
}



void Golpe::set_nome(std::string nome){
    _nome = nome;
}

void Golpe::set_id(int id){
    if(id < 0) {
        throw std::invalid_argument("O ID deve ser um número inteiro positivo.");
    }
    _id = id;
}

void Golpe::set_poderBase(int poderBase){
    if(poderBase < 0) {
        throw std::invalid_argument("O poder base de um golpe deve ser um número inteiro positivo.");
    }
    _poderBase = poderBase;
}

void Golpe::set_precisao(int precisao){
    if(precisao < 0 || precisao > 100){
        throw std::invalid_argument("A precisão é uma porcetagem (entre 0 a 100)");
    }
    _precisao = precisao;
}

void Golpe::set_tipo(Tipo* tipo){
    _tipo = *tipo;
}

void Golpe::set_especial(bool especial){
    _especial = especial;
}