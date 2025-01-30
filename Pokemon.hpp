#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Condicional.hpp"
#include "ModificaEst.hpp"
#include "Habilidade.hpp"
#include "Item.hpp"

// Declaração antecipada da classe Habilidade
class Habilidade;
class Item;

class Pokemon {
    private:
        std::string _nome; // Nome do Pokémon
        int _id; // Número de identificação do Pokémon
        float _estatisticas[6]; // 0 = Vida, 1 = ataque, 2 = defesa, 3 = ataque especial, 4 = defesa especial, 5 = velocidade
        float _vidaAtual; // Valor da vida atual
        float _estagios[6]; // Vetor com os estágios para cada estatística que será afetada. Estágios vão de -6 até 6, -6 representando 2/8 (2/8 = 2/(2+6) = 25%) do original, 0 representando 2/2 (100%) do original e 6 representando 8/2 (8/2 = (2+6)/2 = 400%) do original
        Tipo _tipo1, _tipo2; // Tipos do Pokémon
        int _condicao; // 0 = nenhum, 1 = queimadura, 2 = paralisia, 3 = veneno
        int _lista[8]; // Lista dos números dos golpes que o Pokémon pode aprender
        int _golpes[4]; // Números dos golpes atuais do Pokémon
        Habilidade *_habilidade;   // Ponteiro para sua habilidade escolhida
        Item *_item;      // Ponteiro para seu item escolhido


public:
    Pokemon();

    std::string get_nome();
    int get_id();
    float get_estatistica(int estatistica); // Retorna uma das seis estatísticas do Pokémon
    float get_vidaAtual(); // Retorna a vida atual do Pokémon
    float get_estagio(int estatistica); // Retorna o estágio de uma das 6 estatísticas do Pokémon
    Tipo* get_tipo1();
    Tipo* get_tipo2();
    int get_tipo1Num(); // Retorna o número do tipo 1 do Pokémon
    int get_tipo2Num(); // Retorna o número do tipo 2 do Pokémon
    float get_relacaoTipo(Tipo *tipo, int posicao); // Retorna a relação entre dois tipos
    int get_condicao();
    int get_lista(int posicao); // Retorna o número de um golpe da lista
    int get_golpe(int num); // Retorna o número de um golpe escolhido
    Habilidade &get_habilidade();   // Pega a refência de uma habilidade 
    Item &get_item();            // Pega a refêrencia de um item

    void set_nome(std::string nome);
    void set_id(int id);
    void set_estatistica(int estatistica, float valor); // Altera o valor de uma das seis estatísticas do Pokémon
    void set_vidaAtual(float vidaAtual); // Altera a vida atual do Pokémon
    void set_estagio(int estatistica, float estagio); // Altera o estágio de uma das estatísticas do Pokémon
    void set_tipo1(Tipo *tipo); 
    void set_tipo2(Tipo *tipo);
    void set_condicao(int condicao); // Altera a condição do Pokémon
    void set_lista(int posicao, int num); // Altera o número de um golpe da lista
    void set_golpe(int posicao, int num); // Altera o número de um golpe da escolhido
    void set_habilidade(Habilidade &habilidade);    // Seta uma habilidade 
    void set_item(Item &item);       // Seta um item

    
    float calculaDano(Golpe &golpe, Pokemon &pokemon); // Calcula o dano que o Pokémon causará usando um golpe contra um Pokémon inimigo
    void atacarG(Pokemon* oponente, Golpe* golpes, int golpeEscolhido); // Ataca o Pokémon inimigo com um golpe simples
    void atacarC(Pokemon* oponente, Condicional* condicionais, int golpeEscolhido); // Ataca o Pokémon inimigo com um golpe condicional
    void atacarM(Pokemon* oponente, ModificaEst* modificaests, int golpeEscolhido); // Ataca o Pokémon inimigo com um golpe modificador
};

#endif