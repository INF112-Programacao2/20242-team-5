#include "Estatisticas.hpp"

Estatisticas::Estatisticas(int id) {
    switch (id) {
        case 1: //Charizard
            _vida = 78;
            _ataque = 84;
            _defesa = 78;
            _ataqueEspecial = 109;
            _defesaEspecial = 85;
            _velocidade = 100;
        break;
    }
} 

int Estatisticas::get_vida() const {
    return _vida;
}

int Estatisticas::get_ataque() const {
    return _ataque;
}
    
int Estatisticas::get_defesa() const {
    return _defesa;
}

int Estatisticas::get_ataqueEspecial() const {
    return _ataqueEspecial;
}

int Estatisticas::get_defesaEspecial() const {
    return _defesaEspecial;
}

int Estatisticas::get_velocidade() const {
    return _velocidade;
}
    
