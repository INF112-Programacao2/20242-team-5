#include "Pokemon.hpp"
#include <string>

Pokemon::Pokemon(int id, std::string nome) : _id(id), _nome(nome), _estatisticas(Estatisticas(id)) {}

int Pokemon::get_id(){
    return _id;
}

std::string Pokemon::get_nome() {
    return _nome;
}

int Pokemon::get_vida() const {
    return _estatisticas.get_vida();
}

int Pokemon::get_ataque() const {
    return _estatisticas.get_ataque();
}

int Pokemon::get_defesa() const {
    return _estatisticas.get_defesa();
}

int Pokemon::get_ataqueEspecial() const {
    return _estatisticas.get_ataqueEspecial();
}

int Pokemon::get_defesaEspecial() const {
    return _estatisticas.get_defesaEspecial();
}

int Pokemon::get_velocidade() const {
    return _estatisticas.get_velocidade();
}
