#include "ModificaEst.hpp"

ModificaEst::ModificaEst() {} // Construtor

int ModificaEst::get_estatisticaAfetada(int num){
    return _estatisticasAfetadas[num];
}

int ModificaEst::get_chance(){
    return _chance;
}

bool ModificaEst::is_autoAlvo(){
    return _autoAlvo;
}



void ModificaEst::set_estatisticaAfetada(int estatistica, int estagio){
    if(estagio < -6 || estagio > 6){
        throw std::invalid_argument("Valor do estágio inválido.");
    }
    _estatisticasAfetadas[estatistica] = estagio;
}

void ModificaEst::set_chance(int chance){
    _chance = chance;
}

void ModificaEst::set_autoAlvo(int autoAlvo){
    _autoAlvo = autoAlvo;
}