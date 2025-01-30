#include "Item.hpp"
#include "Pokemon.hpp"

Item::Item() {}

std::string Item::get_nome() const {
    return _nome;
}

std::string Item::get_descricao() const {
    return _descricao;
}

void Item::aplicar_efeito(Pokemon &pokemon) {}
