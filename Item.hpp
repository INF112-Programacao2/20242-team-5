#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
#include "Pokemon.hpp"

// Forward declaration
class Pokemon;


class Item {
    protected:
        std::string _nome_item;
        std::string _descricao;

    public:
        Item(std::string nome, std::string descricao);
        virtual ~Item() = default;

        std::string get_nome_item() const;
        std::string get_descricao_item() const;
        virtual void aplicar_efeito(Pokemon &pokemon) = 0; // Método abstrato
};

#endif
