#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include "Pokemon.hpp"

class Treinador{
    private:
        std::string _nome; // Nome do treinador
        Pokemon _pokemon; // Pokémon escolhido
        
    public:
        Treinador(std::string nome, Pokemon* pokemon); // Construtor
        std::string get_nome();
        Pokemon get_pokemon();
        Pokemon &get_pokemonPonteiro();    // pega a refêrencia do pokémon para aplicar o polimorfismo
        int get_golpePokemon(int posicao); // Retorna o número do golpe do Pokémon
        int get_listaPokemon(int num); // Retorna o número do golpe na lista do Pokémon

        void set_golpePokemon(int posicao, int num); // Altera o número do golpe do Pokémon
};

#endif