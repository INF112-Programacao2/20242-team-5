#include "Treinador.hpp"

Treinador::Treinador(std::string nome, Pokemon *pokemon) : _nome(nome), _pokemon(*pokemon) {}

std::string Treinador::get_nome(){
    return _nome;
}

Pokemon Treinador::get_pokemon(){
    return _pokemon;
}

Pokemon &Treinador::get_pokemonPonteiro(){
    return _pokemon;    // refêrencia do pokemon do treinador
}

int Treinador::get_golpePokemon(int posicao){ // Retorna o número do golpe do Pokémon
    return _pokemon.get_golpe(posicao);
}

int Treinador::get_listaPokemon(int num){ // Retorna o número do golpe na lista do Pokémon
    return _pokemon.get_lista(num);
}



void Treinador::set_golpePokemon(int posicao, int num){ // Altera o número do golpe do Pokémon
    _pokemon.set_golpe(posicao, num);
}