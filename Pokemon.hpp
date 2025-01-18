#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include "Condicional.hpp"
#include "ModificaEst.hpp"
#include "Tipo.hpp"
#include "Golpe.hpp"
#include "Item.hpp"

class Pokemon {
    private:
        int _id; // Identifica o Pokémon
        std::string _nome; // Nome do Pokémon
        int _estatisticas[6]; // 0 = Vida, 1 = ataque, 2 = defesa, 3 = ataque especial, 4 = defesa especial, 5 = velocidade
        int _estagios[6]; // Vetor com os estágios para cada estatística que será afetada. Estágios vão de -6 até 6, -6 representando 2/8 (2/8 = 2/(2+6) = 25%) do original, 0 representando 2/2 (100%) do original e 6 representando 8/2 (8/2 = (2+6)/2 = 400%) do original
        Tipo _tipo1, _tipo2; // Tipos do Pokémon
        int _condicao; // 0 = nenhum, 1 = queimadura, 2 = congelamento, 3 = paralisia, 4 = veneno ou 5 = sono
        Golpe _golpe1, _golpe2, _golpe3, _golpe4; // Golpes atuais do Pokémon

    public:
        Pokemon(int id, std::string nome, int vida, int ataque, int defesa, int ataqueEspecial, int defesaEspecial, int velocidade, Tipo &tipo1, Tipo &tipo2, Golpe golpe1, Golpe golpe2, Golpe golpe3, Golpe golpe4); // Construtor
        int get_id();
        std::string get_nome();
        int get_estatistica(int estatistica); // Retorna uma das 6 estatísticas do Pokémon
        int get_estagio(int estatistica); // Retorna o estágio de uma das 6 estatísticas do Pokémon
        Tipo get_tipo1();
        Tipo get_tipo2();
        int get_tipo1Num();
        int get_tipo2Num();
        int get_relacaoTipo(Tipo tipo, int posicao); // Retorna a relação entre dois tipos
        int get_condicao();

        void set_nome(std::string nome); // Para apelidar o Pokémon
        void set_estatistica(int estatistica, int valor);  // Setar novo valor nas estatísticas
        void set_condicao(int condicao); // Altera a condição do Pokémon
        void set_estagio(int estatistica, int estagio); // Altera o estágio de uma das estatísticas do Pokémon


        float calculaDano(Golpe &golpe, Pokemon &pokemon); // Calcula o dano de um golpe contra um Pokémon
        void ativar_item(Item &item);
};

#endif
