#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
    private:
        std::string _nome;
        std::string _descricao;
        float _efeito; 

    public:
        Item(std::string nome, std::string descricao, float efeito); 
        std::string get_nome();
        float get_efeito();
    
};

#endif
