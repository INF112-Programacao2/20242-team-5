#ifndef HABILIDADES_HPP
#define HABILIDADES_HPP

#include "Habilidade.hpp"
#include "Pokemon.hpp"

class Cura : public Habilidade {
    public:
        Cura() {
            _nome = "Cura";
            _descricao = "Recupera 25 de vida ao Pokémon por turno.";

        }

        void aplicar(Pokemon &pokemon) override {
            int novaVida = pokemon.get_vidaAtual() + (pokemon.get_estatistica(0)/16);
            if (novaVida > pokemon.get_estatistica(0)) { // Verifica se não ultrapassa a vida máxima
                novaVida = pokemon.get_estatistica(0);
                std::cout << "Habilidade não fez efeito, vida está no máximo\n";
                return;
            }
            pokemon.set_vidaAtual(novaVida);  // Recupera vida
            std::cout << pokemon.get_nome() << " usou a habilidade Cura e recuperou 25 de vida!\n";
        }
};

class AumentarAgressividade : public Habilidade {
public:
    AumentarAgressividade() {
        _nome = "Aumentar Agressividade";
        _descricao = "Aumenta o ataque e velocidade do Pokémon em 1 estágio.";
    }

    void aplicar(Pokemon &pokemon) override {
        pokemon.set_estagio(1, pokemon.get_estagio(1) + 1); // Aumenta o ataque em 1 estágio
        pokemon.set_estagio(1, pokemon.get_estagio(5) + 1); // Aumentar a velocidade em 1 estágio
        std::cout << pokemon.get_nome() << " ativou a habilidade Aumentar Agressividade!\n";

    }
};

class AumentarDefesa : public Habilidade {
    public:
        AumentarDefesa() {
            _nome = "Aumentar Defesas";
            _descricao = "Aumenta as defesas do Pokémon em 1 estágio";
        }

        void aplicar(Pokemon &pokemon) override {
            pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);  // Aumenta a defesa em 1 estágio
            pokemon.set_estagio(4, pokemon.get_estagio(4) + 1);  // Aumenta a defesa ESPECIAL em 1 estágio
            std::cout << pokemon.get_nome() << " ativou a habilidade Aumentar Defesas!\n";
        }
};

class VelocidadeAumentada : public Habilidade {
    public:
        VelocidadeAumentada() {
            _nome = "Velocidade Aumentada";
            _descricao = "Aumenta a velocidade do Pokémon em 2 estágio";
        }

        void aplicar(Pokemon &pokemon) override {
            pokemon.set_estagio(5, pokemon.get_estagio(5) + 2);  // Aumenta a velocidade em 2 estágio
            std::cout << pokemon.get_nome() << " ativou a habilidade Velocidade Aumentada!\n";
        }
};

#endif