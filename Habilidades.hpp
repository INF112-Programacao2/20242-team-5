#ifndef HABILIDADES_HPP_INCLUDED
#define HABILIDADES_HPP_INCLUDED

#include "Pokemon.hpp"

class Habilidades {
    protected:
        std::string _nome;
        bool _estaAtiva;
    public:
        //fun��es get
        virtual std::string get_name ( ) =0;
        virtual bool get_estaAtiva ( ) = 0;

        //fun��es set
        virtual bool set_estaAtiva ( bool estaAtiva) = 0;

        //fun��es
        virtual void funcao ( ) = 0;
};

#endif // HABILIDADES_HPP_INCLUDED
