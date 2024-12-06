#ifndef Pokemon_HPP
#define Pokemon_HPP

#include <string>
#include "tipo.h"
#include "itens.h"
#include "golpe.h"

class Pokemon {
    int _id;
    std::string _nome;
    Tipo _tipagem[2];
    int _estatisticas[6]; // vida, ataque, defesa, ataque especial, defesa especial, velocidade
    bool status;
    Item _item;
    //habilidade
    Golpe _golpes[4];
};

#endif
