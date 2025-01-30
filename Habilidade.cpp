#include "Habilidade.hpp"

Habilidade::Habilidade() {}

std::string Habilidade::get_nome() const {
    return _nome;
}

std::string Habilidade::get_descricao() const {
    return _descricao;
}

void Habilidade::aplicar(Pokemon &pokemon) {}