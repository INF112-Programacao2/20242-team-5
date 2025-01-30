#ifndef HABILIDADE_HPP
#define HABILIDADE_HPP

#include <string>
#include <iostream>

// Forward declaration
class Pokemon;

class Habilidade {
    protected:
        std::string _nome;
        std::string _descricao;

    public:
        Habilidade();
        std::string get_nome() const;   // Pega o nome da habilidade
        std::string get_descricao() const;  // Pega a descrição da habilidade 

        virtual void aplicar(Pokemon &pokemon) = 0; // Método virtual puro, vai aplicar o polimorfismo da habilidade
        virtual ~Habilidade() {}
};

#endif 
