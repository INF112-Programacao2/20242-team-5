#ifndef BATALHA_HPP
#define BATALHA_HPP

#include <iostream>
#include <stdexcept>
#include "Pokemon.hpp"
#include "Golpe.hpp"

class Batalha {
    private:
        Pokemon *_pokemon1;
        Pokemon *_pokemon2;
        int _turnoAtual; // Contador de turnos

        // Método para calcular quem ataca primeiro
        Pokemon *determinarIniciativa();

    public:
        Batalha(Pokemon *pokemon1, Pokemon *pokemon2);

        void iniciar(); // Inicia o combate
        void turno(Pokemon *atacante, Pokemon *defensor); // Gerencia um turno de ataque
        bool verificaDerrota(Pokemon *pokemon); // Verifica se um Pokémon foi derrotado
};

#endif
