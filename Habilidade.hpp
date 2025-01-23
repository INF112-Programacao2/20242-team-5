#ifndef HABILIDADE_HPP
#define HABILIDADE_HPP

#include "Pokemon.hpp"
#include <string>

class Habilidade {
protected:
    std::string _nome;  // nome da habilidade
    std::string _descricao;  // descrição do efeito da habilidade

public:
    Habilidade(std::string nome, std::string descricao);
    virtual ~Habilidade() = default;

    std::string get_nome() const;
    std::string get_descricao() const;

    // método virtual puro, será sobrescrito nas subclasses
    virtual void aplicar(Pokemon &pokemon) = 0;
};

#endif

// Subclasse para a habilidade "Cura"
class Cura : public Habilidade {
public:
    Cura() : Habilidade("Cura", "Recupera 20 de vida ao Pokémon por turno") {}

    void aplicar(Pokemon &pokemon) override {
        int novaVida = pokemon.get_estatistica(0) + 20;  
        if (novaVida > pokemon.get_vidaMaxima()) {
            novaVida = pokemon.get_vidaMaxima();
        }
        pokemon.set_estatistica(0, novaVida);  // Recupera vida
        std::cout << pokemon.get_nome() << " usou a habilidade Cura e recuperou 20 de vida!\n";
    }
};

class Intimidate : public Habilidade {
public:
    Intimidate() : Habilidade("Intimidate", "Reduz o ataque do oponente ao entrar em campo") {}

    void aplicar(Pokemon &pokemon) override {   
        //oponente.set_estagio(1, oponente.get_estagio(1) - 1);  // Índice 1 é o ataque
        std::cout << pokemon.get_nome() << " usou a habilidade Intimidate! O ataque do oponente foi reduzido!\n";
    }
};


// Subclasse para a habilidade "Aumentar Ataque"
class AumentarAtaque : public Habilidade {
public:
    AumentarAtaque() : Habilidade("Aumentar Ataque", "Aumenta o ataque do Pokémon em 1 estágio") {}

    void aplicar(Pokemon &pokemon) override {
        pokemon.set_estagio(1, pokemon.get_estagio(1) + 1);  // Índice 1 é o ataque
        std::cout << pokemon.get_nome() << " usou a habilidade Aumentar Ataque!\n";
    }
};

// Subclasse para a habilidade "Aumentar Defesa"
class AumentarDefesa : public Habilidade {
public:
    AumentarDefesa() : Habilidade("Aumentar Defesa", "Aumenta a defesa do Pokémon em 1 estágio") {}

    void aplicar(Pokemon &pokemon) override {
        pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);  // Índice 2 é a defesa
        std::cout << pokemon.get_nome() << " usou a habilidade Aumentar Defesa!\n";
    }
};

// Subclasse para a habilidade "Velocidade Aumentada"
class VelocidadeAumentada : public Habilidade {
public:
    VelocidadeAumentada() : Habilidade("Velocidade Aumentada", "Aumenta a velocidade do Pokémon em 1 estágio") {}

    void aplicar(Pokemon &pokemon) override {
        pokemon.set_estagio(5, pokemon.get_estagio(5) + 1);  // Índice 5 é a velocidade
        std::cout << pokemon.get_nome() << " usou a habilidade Velocidade Aumentada!\n";
    }
};
