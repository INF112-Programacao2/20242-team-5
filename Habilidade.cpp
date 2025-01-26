#include "Habilidade.hpp"

Habilidade::Habilidade(std::string nome, std::string descricao) : _nome(nome), _descricao(descricao) {}

std::string Habilidade::get_nome() const {
    return _nome;
}

std::string Habilidade::get_descricao() const {
    return _descricao;
}
