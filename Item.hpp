#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
#include "C:\Users\chell\Documents\inf 112\projeto final\codigo\Pokemon.hpp"

// Classe base abstrata
class Item {
protected:
    std::string _nome_item;
    std::string _descricao;

public:
    Item(std::string nome, std::string descricao);
    virtual ~Item() = default;

    std::string get_nome_item() const;
    virtual void aplicar_efeito(Pokemon &pokemon) = 0; // método virtual puro
};

#endif

// Subclasse de Item para "X Attack"
class XAttack : public Item {
    public:
        XAttack() : Item("X Attack", "Aumenta o ataque do Pokémon") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(1, pokemon.get_estagio(1) + 1);  // índice 1 é o ataque
        }
};

// Subclasse de Item para "X Defense"
class XDefense : public Item {
    public:
        XDefense() : Item("X Defense", "Aumenta a defesa do Pokémon") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);  // índice 2 é a defesa
        }
};

// Subclasse de Item para "X Speed"
class XSpeed : public Item {
    public:
        XSpeed() : Item("X Speed", "Aumenta a velocidade do Pokémon") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(5, pokemon.get_estagio(5) + 1);  // índice 5 é a velocidade
        }
};

// Subclasse de Item para "Deep Sea Tooth"
class DeepSeaTooth : public Item {
    public:
        DeepSeaTooth() : Item("Deep Sea Tooth", "Aumenta a força do Pokémon") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(3, pokemon.get_estagio(3) + 1);  // índice 3 é a força
        }
};

// Subclasse de Item para "Deep Sea Scale"
class DeepSeaScale : public Item {
    public:
        DeepSeaScale() : Item("Deep Sea Scale", "Aumenta a resistência do Pokémon") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            pokemon.set_estagio(4, pokemon.get_estagio(4) + 1);  // índice 4 é a resistência
        }
};

// Subclasse de Item para "Berserk Band"
class BerserkBand : public Item {
    public:
        BerserkBand() : Item("Berserk Band", "Aumenta o ataque do Pokémon quando a vida estiver baixa") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            if (pokemon.get_estatistica(0) <= pokemon.get_vidaMaxima() / 2) {
                pokemon.set_estagio(1, pokemon.get_estagio(1) + 2);  // Aumenta o ataque
            }
        }
};

// Subclasse de Item para "Endure Scarf"
class EndureScarf : public Item {
public:
    EndureScarf() : Item("Endure Scarf", "Aumenta a defesa do Pokémon quando a vida estiver muito baixa") {}

    void aplicar_efeito(Pokemon &pokemon) override {
        if (pokemon.get_estatistica(0) < pokemon.get_vidaMaxima() / 4) {
            pokemon.set_estagio(2, pokemon.get_estagio(2) + 2);  // Aumenta a defesa
        }
    }
};

// Subclasse de Item para "Oran Berry"
class OranBerry : public Item {
    public:
        OranBerry() : Item("Oran Berry", "Recupera 20 de vida ao ser consumida") {}

        void aplicar_efeito(Pokemon &pokemon) override {
            if (pokemon.get_estatistica(0) < pokemon.get_vidaMaxima() / 2) {
                int novaVida = pokemon.get_estatistica(0) + 20;  
                pokemon.set_estatistica(0, novaVida);   // Recupera vida
                std::cout << pokemon.get_nome() << " consumiu a Oran Berry e recuperou 20 de vida!\n";
            }
        }
};
