#ifndef Estatisticas_HPP
#define Estatisticas_HPP

class Estatisticas {
    private:
        int _vida;
        int _ataque;
        int _defesa;
        int _ataqueEspecial;
        int _defesaEspecial;
        int _velocidade;
    
    public:
        Estatisticas(int id);

        int get_vida() const;
        int get_ataque() const;
        int get_defesa() const;
        int get_ataqueEspecial() const;
        int get_defesaEspecial() const;
        int get_velocidade() const;
};

#endif
