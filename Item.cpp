#include "Item.hpp"

Item::Item(std::string nome, std::string descricao, float efeito)
    : _nome(nome), _descricao(descricao), _efeito(efeito) {}

std::string Item::get_nome() {
    return _nome;
}

float Item::get_efeito() {
    return _efeito;
}
