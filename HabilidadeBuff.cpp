#include <iostream>
#include "Habilidades.hpp"
#include "HabilidadeBuff.hpp"

//implementa��o Costrutor
HabBuff::HabBuff ( std::string nome, float fatorMultiplicacao ) :
    _nome (nome), _fatorMultiplicacao (fatorMultiplicacao), _estaAtiva (estaAtiva) {};

//implementa��o fun��es get
std:: string HabBuff::get_name ( ) {
    return this->_name
};

float HabBuff::get_fatorMultiplicacao ( ) {
    retun this->_fator_multiplicacao
}

bool HabBuff::get_estaAtiva ( ) {
    return this->_estaAtiva;
}

//implementa��o das fun��es set
bool HabBuff::set_estaAtiva ( bool estaAtiva ) {
    _estaAtiva = estaAtiva;
}

/*implementa��o fun��es padr�o
void HabBuff::funcao ( ) {
    if ( get_estaAtiva( ) ) {
     implementarei depois, preciso de discutir algumas coisas com voc�s antes
    }
}
*/
