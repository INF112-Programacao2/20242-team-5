#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Condicional.hpp"
#include "ModificaEst.hpp"
#include "Tipo.hpp"
#include "Golpe.hpp"
#include "Habilidade.hpp"
#include "Item.hpp"

// Forward declarations
class Item;
class Habilidade;

class Pokemon {
    private:
        int _id; // Identifica o Pokémon
        std::string _nome; // Nome do Pokémon
        int _estatisticas[6]; // 0 = Vida, 1 = ataque, 2 = defesa, 3 = ataque especial, 4 = defesa especial, 5 = velocidade
        int _estagios[6]; // Vetor com os estágios para cada estatística que será afetada. Estágios vão de -6 até 6, -6 representando 2/8 (2/8 = 2/(2+6) = 25%) do original, 0 representando 2/2 (100%) do original e 6 representando 8/2 (8/2 = (2+6)/2 = 400%) do original
        Tipo _tipo1, _tipo2; // Tipos do Pokémon
        int _condicao; // 0 = nenhum, 1 = queimadura, 2 = congelamento, 3 = paralisia, 4 = veneno ou 5 = sono
        Golpe _golpe1, _golpe2, _golpe3, _golpe4; // Golpes atuais do Pokémon
        Item *_item;
        Habilidade *_habilidade;

        int _estatisticas_calculos[6];

public:
    Pokemon(int id, std::string nome, int vida, int ataque, int defesa, int ataqueEspecial, int defesaEspecial, int velocidade, const Tipo &tipo1, const Tipo &tipo2, const Golpe &golpe1, const Golpe &golpe2, const Golpe &golpe3, const Golpe &golpe4);

    int get_id() const;
    std::string get_nome() const;
    int get_estatistica(int estatistica) const; // Retorna uma das 6 estatísticas do Pokémon
    int get_estatistica_calculos(int estatistica) const;
    int get_estagio(int estatistica) const; // Retorna o estágio de uma das 6 estatísticas do Pokémon
    Tipo get_tipo1() const;
    Tipo get_tipo2() const;
    int get_tipo1Num();
    int get_tipo2Num();
    int get_relacaoTipo(Tipo tipo, int posicao) const; // Retorna a relação entre dois tipos
    int get_condicao() const;
    Golpe get_golpe1() const;
    Golpe get_golpe2() const;
    Golpe get_golpe3() const;
    Golpe get_golpe4() const;

    void set_nome(std::string nome); // Para apelidar o Pokémon
    void set_estatistica(int estatistica, int valor);  // Setar novo valor nas estatísticas
    void set_condicao(int condicao); // Altera a condição do Pokémon
    void set_estagio(int estatistica, int estagio); // Altera o estágio de uma das estatísticas do Pokémon
    void set_item(Item *item);
    void set_habilidade(Habilidade *habilidade); 
    
    void usar_item();
    void usar_habilidade();
    float calculaDano(Golpe &golpe, Pokemon &pokemon);
};

#endif
