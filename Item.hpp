#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
#include "Pokemon.hpp"

class Item {
    private:
        std::string _nome_item;
        std::string _descricao;
        bool _ativo; 

    public:
        Item(std::string nome, std::string descricao, bool ativo); 
        std::string get_nome_item() const;
        bool get_ativo() const;
        void aplicar_efeito(Pokemon &pokemon);
    
};

#endif
