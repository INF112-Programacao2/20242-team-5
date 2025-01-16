#ifndef TIPO_HPP
#define TIPO_HPP

#include <string>

class Tipo{
    private:
        std::string _nome;
        int _numRep; // Número que irá representar o tipo
        float _relacoes[19][19];
        
    public:
        Tipo(); // Construtor
        std::string get_nome();
        void set_nome(std::string nome);
        int get_numRep();
        void set_numRep(int numRep);
        float get_relacao(int tipo1, int tipo2);
};

#endif