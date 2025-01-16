#include "Pokemon.hpp"
#include <iostream>
#include <fstream>

int main(){
    Tipo tipos[18];
    std::ifstream entrada("tipos.txt");

    for(int i=0; i<18; i++){
        std::string string;
        entrada >> string;
        tipos[i].set_nome(string);
        int num;
        entrada >> num;
        tipos[i].set_numRep(num);
    }

    entrada.close();

    return 0;
}