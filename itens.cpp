#include <itens.h>

void Item::hpBerry(){
    _vidaPokemon += 50;
}

void Item::wacanBerry(){
    // if(_tipoOponente = tipo Eletrico)    
    _resistencia = 1.3; // Reduzirá o dano recebido em 30%, aumentando a resistência em 30%
}   // A ser analisada posteriormente. Vai depender do vetor tipo adversario e como afeta cada tipo de forma diferente

void Item::pechaBerry(){
    if(_envenenamento)
        _envenenamento = false;
}

void Item::gemaAtaque(){
    _poderBase *= 1.2;  // Aumenta a força do ataque em 20%
}

void Item::gemaResist(){
    _resistencia = 1.2; // Reduz o dano total recebido em 20%, aumentando a resistência
}

void Item::gemaChance(){
    _precisao *= 1.2;   // Aumenta a chance (ou precisão do golpe) em 20%
}
