#ifndef ITEMS_HPP
#define ITEMS_HPP

#include "Item.hpp"
#include "Pokemon.hpp"

// Subclasse de Item para "X Attack"
class XAttack : public Item {
    public:
        XAttack() {
            _nome = "X Attack";
            _descricao = "Aumenta o ataque do Pokémon";
        }

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(1, pokemon.get_estagio(1) + 1);  // índice 1 é o ataque
            std::cout << ", o ataque do seu Pokémon subiu 1 estágio!\n";
        }
};

// Subclasse de Item para "X Defense"
class XDefense : public Item {
    public:
        XDefense() {
            _nome = "X Defense";
            _descricao = "Aumenta a defesa do Pokémon";
        }

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);  // índice 2 é a defesa
            std::cout << ", a defesa do seu Pokémon subiu 1 estágio!\n";
        }
};

// Subclasse de Item para "X Speed"
class XSpeed : public Item {
    public:
        XSpeed() {
            _nome = "X Speed";
            _descricao = "Aumenta a velocidade do Pokémon";
        }

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(5, pokemon.get_estagio(5) + 1);  // índice 5 é a velocidade
            std::cout << ", a velocidade do seu Pokémon subiu 1 estágio!\n";
        }
};

// Subclasse de Item para "Deep Sea Scale"
class DeepSeaScale : public Item {
    public:
        DeepSeaScale() {
            _nome = "Deep Sea Scale";
            _descricao = "Aumenta a defesa especial do Pokémon";
        }

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(4, pokemon.get_estagio(4) + 1);  // índice 4 é a resistência
            std::cout << ", a defesa especial do seu Pokémon subiu 1 estágio!\n";
        }
};


#endif