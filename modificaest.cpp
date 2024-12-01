#include "modificaest.h"

ModificaEst::ModificaEst(std::string nome, int poderBase, int precisao, Tipo tipo, bool especial, int estagioAtaque, int estagioDefesa, int estagioAtaqueEsp, int estagioDefesaEsp, int estagioVelocidade, int chance, bool autoAlvo) : Golpe(nome, poderBase, precisao, tipo, especial),  _chance(chance), _autoAlvo(autoAlvo) { // Construtor
    _estatisticasAfetadas[1] = estagioAtaque;
    _estatisticasAfetadas[2] = estagioDefesa;
    _estatisticasAfetadas[3] = estagioAtaqueEsp;
    _estatisticasAfetadas[4] = estagioDefesaEsp;
    _estatisticasAfetadas[5] = estagioVelocidade;
}

int* ModificaEst::get_estatisticasAfetadas(){
    return _estatisticasAfetadas;
}

int ModificaEst::get_chance(){
    return _chance;
}

bool ModificaEst::is_autoAlvo(){
    return _autoAlvo;
}