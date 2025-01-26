#include "Pokemon.hpp"
#include <iostream>
#include <fstream>

int main(){
    int num;
    std::string nome;
    Tipo tipos[19];
    std::ifstream entrada("tipos.txt");

    for(int i=0; i<18; i++){
        entrada >> nome;
        tipos[i+1].set_nome(nome);
        float n;
        entrada >> n;
        tipos[i+1].set_numRep(n);
        for(int j=0; j<18; j++){
            entrada >> n;
            tipos[0].set_relacao(n, i+1, j+1);
        }
    }

    entrada.close();

    entrada.open("golpes.txt");

    Golpe* golpes;
    Condicional* condicionais;
    ModificaEst* modificaests;

    int tamanho;
    entrada >> tamanho;
    golpes = new Golpe[tamanho];
    for(int i=0; i<tamanho; i++){
        entrada >> nome;
        golpes[i].set_nome(nome);
        entrada >> num;
        golpes[i].set_poderBase(num);
        entrada >> num;
        golpes[i].set_precisao(num);
        entrada >> num;
        golpes[i].set_tipo(tipos[num]);
        entrada >> num;
        golpes[i].set_especial(num);
    }

    entrada >> tamanho;
    condicionais = new Condicional[tamanho];
    for(int i=0; i<tamanho; i++){
        entrada >> nome;
        condicionais[i].set_nome(nome);
        entrada >> num;
        condicionais[i].set_poderBase(num);
        entrada >> num;
        condicionais[i].set_precisao(num);
        entrada >> num;
        condicionais[i].set_tipo(tipos[num]);
        entrada >> num;
        condicionais[i].set_especial(num);
        entrada >> num;
        condicionais[i].set_condicao(num);
        entrada >> num;
        condicionais[i].set_chance(num);
    }

    entrada >> tamanho;
    modificaests = new ModificaEst[tamanho];
    for(int i=0; i<tamanho; i++){
        entrada >> nome;
        modificaests[i].set_nome(nome);
        entrada >> num;
        modificaests[i].set_poderBase(num);
        entrada >> num;
        modificaests[i].set_precisao(num);
        entrada >> num;
        modificaests[i].set_tipo(tipos[num]);
        entrada >> num;
        modificaests[i].set_especial(num);
        for(int j=1; j<6; j++){
            entrada >> num;
            modificaests[i].set_estatisticasAfetadas(j, num);
        }
        entrada >> num;
        modificaests[i].set_chance(num);
        entrada >> num;
        modificaests[i].set_autoAlvo(num);
    }

    entrada.close();

    delete[] golpes;
    delete[] condicionais;
    delete[] modificaests;
    
    return 0;
}