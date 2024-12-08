#include <iostream>
#include "Habilidades.hpp"
#include "HabilidadeBuff.hpp"

//implementação Costrutor
HabBuff::HabBuff ( std::string nome, float fatorMultiplicacao ) :
    _nome (nome), _fatorMultiplicacao (fatorMultiplicacao), _estaAtiva (estaAtiva) {};

//implementação funções get
std:: string HabBuff::get_name ( ) {
    return this->_name
};

float HabBuff::get_fatorMultiplicacao ( ) {
    retun this->_fator_multiplicacao
}

bool HabBuff::get_estaAtiva ( ) {
    return this->_estaAtiva;
}

//implementação das funções set
bool HabBuff::set_estaAtiva ( bool estaAtiva ) {
    _estaAtiva = estaAtiva;
}

/*implementação funções padrão
void HabBuff::funcao ( ) {
    if ( get_estaAtiva( ) ) {
     implementarei depois, preciso de discutir algumas coisas com vocês antes
    }
}
*/
