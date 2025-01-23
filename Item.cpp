#include "Item.hpp"

Item::Item(std::string nome, std::string descricao) : _nome_item(nome), _descricao(descricao) {}

std::string Item::get_nome_item() const {
    return _nome_item;  
}
