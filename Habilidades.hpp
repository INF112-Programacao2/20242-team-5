#include "Habilidade.hpp"
#include "Pokemon.hpp"

class Cura : public Habilidade {
    public:
        Cura() : Habilidade("Cura", "Recupera 20 de vida ao Pokémon por turno") {}

        void aplicar(Pokemon &pokemon) override {
            int novaVida = pokemon.get_estatistica(0) + 20;  
            if (novaVida > pokemon.get_estatistica_calculos(0)) { // Verifica se não ultrapassa a vida máxima
                novaVida = pokemon.get_estatistica_calculos(0);
            }
            pokemon.set_estatistica(0, novaVida);  // Recupera vida
            std::cout << pokemon.get_nome() << " usou a habilidade Cura e recuperou 20 de vida!\n";
        }
};

class AumentarAtaque : public Habilidade {
    public:
        AumentarAtaque() : Habilidade("Aumentar Ataque", "Aumenta o ataque do Pokémon em 1 estágio") {}

        void aplicar(Pokemon &pokemon) override {
            pokemon.set_estagio(1, pokemon.get_estagio(1) + 1);  // Aumenta o ataque em 1 estágio
            std::cout << pokemon.get_nome() << " usou a habilidade Aumentar Ataque!\n";
        }
};

class AumentarDefesa : public Habilidade {
    public:
        AumentarDefesa() : Habilidade("Aumentar Defesa", "Aumenta a defesa do Pokémon em 1 estágio") {}

        void aplicar(Pokemon &pokemon) override {
            pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);  // Aumenta a defesa em 1 estágio
            std::cout << pokemon.get_nome() << " usou a habilidade Aumentar Defesa!\n";
        }
};

class VelocidadeAumentada : public Habilidade {
    public:
        VelocidadeAumentada() : Habilidade("Velocidade Aumentada", "Aumenta a velocidade do Pokémon em 1 estágio") {}

        void aplicar(Pokemon &pokemon) override {
            pokemon.set_estagio(5, pokemon.get_estagio(5) + 1);  // Aumenta a velocidade em 1 estágio
            std::cout << pokemon.get_nome() << " usou a habilidade Velocidade Aumentada!\n";
        }
};
