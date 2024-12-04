#ifndef ITENS_H
#define ITENS_H

#include <string>
#include "golpe.h"

class Item {
    protected:
        std::string _item;
        float _resistencia = 1.00;
        bool _envenenamento;    // Alterada em versões posteriores, ao aplicado o efeito

        // Variáveis que serão alteradas futuramente, pois viriam dos Pokémons ou de outras classes
        int _vidaPokemon;
        int _relacoes[18];
        bool _efeito;   // Utilizada quando o efeito de envenenamento é aplicado

    public:
        void hpBerry();
        void wacanBerry();
        void pechaBerry();
        void gemaAtaque();
        void gemaResist();
        void gemaChance();
};

#endif /*ITENS_H*/
