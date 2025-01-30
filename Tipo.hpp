#ifndef TIPO_HPP
#define TIPO_HPP

#include <string>
#include <stdexcept>

class Tipo{
    private:
        std::string _nome; // Nome do tipo
        int _numRep; // Número que irá representar o tipo
        static float _relacoes[18][18]; // Matriz com as relações de cada tipo com todos os outros
        
    public:
        Tipo(); // Construtor
        std::string get_nome();
        int get_numRep();
        float get_relacao(int tipo1, int tipo2); // Retorna a relação entre dois tipos

        void set_nome(std::string nome);
        void set_numRep(int numRep);
        void set_relacao(float valor, int tipo1, int tipo2); // Coloca a relação entre dois tipos
};

#endif