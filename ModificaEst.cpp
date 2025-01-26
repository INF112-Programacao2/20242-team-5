#include "ModificaEst.hpp"

ModificaEst::ModificaEst() {} // Construtor

int* ModificaEst::get_estatisticasAfetadas(){
    return _estatisticasAfetadas;
}

int ModificaEst::get_chance() const {
    return _chance;
}

void ModificaEst::set_estatisticasAfetadas(int estatistica, int estagio){
    _estatisticasAfetadas[estatistica] = estagio;
}

void ModificaEst::set_chance(int chance){
    _chance = chance;
}

void ModificaEst::set_autoAlvo(int autoAlvo){
    _autoAlvo = autoAlvo;
}


bool ModificaEst::is_autoAlvo(){
    return _autoAlvo;
}
