#ifndef HABILIDADEBUFF_HPP_INCLUDED
#define HABILIDADEBUFF_HPP_INCLUDED

class HabBuff : public Habilidades {
    private:
        float _fatorMultiplicacao;
    public:

        //construtor
        HabBuff ( std::string nome, float fatorMultiplicacao, bool estaAtiva );

        //fun��es get
        virtual std::string get_name ( ) override;
        virtual bool get_estaAtiva ( ) override;
        float get_fatorMultiplicacao ( ) ;

        //fun��es set
        virtual bool set_estaAtiva ( bool estaAtiva ) override;

        //fun��es padr�o
        virtual void funcao ( ) override;
};

#endif // HABILIDADEBUFF_HPP_INCLUDED
