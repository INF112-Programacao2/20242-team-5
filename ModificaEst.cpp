#include "ModificaEst.hpp"

ModificaEst::ModificaEst() {} // Construtor

int* ModificaEst::get_estatisticasAfetadas(){
    return _estatisticasAfetadas;
}

void ModificaEst::set_estatisticasAfetadas(int estatistica, int estagio){
    _estatisticasAfetadas[estatistica] = estagio;
}

int ModificaEst::get_chance(){
    return _chance;
}

void ModificaEst::set_chance(int chance){
    _chance = chance;
}

bool ModificaEst::is_autoAlvo(){
    return _autoAlvo;
}

void ModificaEst::set_autoAlvo(int autoAlvo){
    _autoAlvo = autoAlvo;
}
