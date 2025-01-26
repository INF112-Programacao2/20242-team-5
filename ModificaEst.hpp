#ifndef MODIFICAEST_HPP
#define MODIFICAEST_HPP

#include "Golpe.hpp"

class ModificaEst : public Golpe{ // Uma espécie de golpes que modifica as estatísticas de um Pokémon
    private:
        int _estatisticasAfetadas[6]; // Vetor com os estágios para cada estatística que será afetada. Estágios vão de -6 até 6, -6 representando 2/8 (2/8 = 2/(2+6) = 25%) do original, 0 representando 2/2 (100%) do original e 6 representando 8/2 (8/2 = (2+6)/2 = 400%) do original. 0 = PV (não utilizado), 1 = ataque, 2 = defesa, 3 = ataque especial, 4 = defesa especial e 5 = velocidade.
        int _chance; // Chance de modificar as estatísticas
        bool _autoAlvo; // Determina se afeta o oponente ou o próprio usuário

    public:
        ModificaEst(); // Construtor

        int *get_estatisticasAfetadas();
        int get_chance() const;

        void set_estatisticasAfetadas(int estatistica, int estagio);
        void set_chance(int chance);
        void set_autoAlvo(int autoAlvo);

        bool is_autoAlvo();
};

#endif
