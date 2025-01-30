#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

// Forward declaration
class Pokemon;

class Item {
    protected:
        std::string _nome;
        std::string _descricao;

    public:
        Item();
        std::string get_nome() const;   // Pega nome do item
        std::string get_descricao() const;  // Pega descrição do item

        virtual void aplicar_efeito(Pokemon &pokemon) = 0; // Método virtual puro
        virtual ~Item() {}
};

#endif
