#ifndef HABILIDADE_HPP
#define HABILIDADE_HPP

#include <string>

// Forward declaration
class Pokemon;

class Habilidade {
    protected:
        std::string _nome;
        std::string _descricao;

    public:
        Habilidade(std::string nome, std::string descricao);
        virtual ~Habilidade() = default;

        std::string get_nome() const;
        std::string get_descricao() const;
        virtual void aplicar(Pokemon &pokemon) = 0;
};

#endif
