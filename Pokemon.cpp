#include "Pokemon.hpp"

Pokemon::Pokemon(int id, std::string nome, int vida, int ataque, int defesa, int ataqueEspecial, int defesaEspecial, int velocidade, Tipo &tipo1, Tipo &tipo2, Golpe golpe1, Golpe golpe2, Golpe golpe3, Golpe golpe4) : _id(id), _nome(nome), _tipo1(tipo1), _tipo2(tipo2), _golpe1(golpe1), _golpe2(golpe2), _golpe3(golpe3), _golpe4(golpe4) {
    _estatisticas[0] = vida;
    _estatisticas[1] = ataque;
    _estatisticas[2] = defesa;
    _estatisticas[3] = ataqueEspecial;
    _estatisticas[4] = defesaEspecial;
    _estatisticas[5] = velocidade;
    _condicao = 0; // Começa sem condição
    for(int i=0; i<6; i++)
        _estagios[i] = 0; // Começa com todos os estágios no 0
}

int Pokemon::get_id(){
    return _id;
}

std::string Pokemon::get_nome() {
    return _nome;
}

void Pokemon::set_nome(std::string nome) { // Para apelidos
    _nome = nome;
}

int Pokemon::get_estatistica(int estatistica){ // Retorna uma das 6 estatísticas do Pokémon
    return _estatisticas[estatistica]; 
}

void Pokemon::set_estatistica(int estatistica, int valor){
    _estatisticas[estatistica] = valor; 
}


int Pokemon::get_estagio(int estatistica){ // Retorna o estágio de uma das 6 estatísticas do Pokémon
    return _estagios[estatistica];
}

void Pokemon::set_estagio(int estatistica, int estagio){ // Altera o estágio de uma das estatísticas do Pokémon
    _estagios[estatistica] = estagio;
}

Tipo Pokemon::get_tipo1(){
    return _tipo1;
}

Tipo Pokemon::get_tipo2(){
    return _tipo2;
}

int Pokemon::get_tipo1Num(){
    return _tipo1.get_numRep();
}

int Pokemon::get_tipo2Num(){
    return _tipo2.get_numRep();
}

int Pokemon::get_relacaoTipo(Tipo tipo, int posicao){ // Retorna a relação entre dois tipos
    return tipo.get_relacao(tipo.get_numRep(), (posicao));
}

int Pokemon::get_condicao(){
    return _condicao;
}

void Pokemon::set_condicao(int condicao){ // Altera a condição do Pokémon
    _condicao = condicao;
}

float Pokemon::calculaDano(Golpe &golpe, Pokemon &pokemon){ // Calcula o dano de um golpe contra um Pokémon
    float dano;

    if(!golpe.is_especial()) // Verifica se é físico ou especial
        dano = ((22 * golpe.get_poderBase() * ((this->get_estatistica(1)*(2+this->get_estagio(1))/2) / (pokemon.get_estatistica(2)*(2+pokemon.get_estagio(2))/2)))/50 + 2) * get_relacaoTipo(pokemon.get_tipo1(), golpe.get_tipoNum()) * get_relacaoTipo(pokemon.get_tipo2(), golpe.get_tipoNum()); // Fórmula adaptada da geração 5 para frente que pode ser encontrada aqui: https://bulbapedia.bulbagarden.net/wiki/Damage
    else
        dano = ((22 * golpe.get_poderBase() * ((this->get_estatistica(3)*(2+this->get_estagio(3))/2) / (pokemon.get_estatistica(4)*(2+pokemon.get_estagio(4))/2)))/50 + 2) * get_relacaoTipo(pokemon.get_tipo1(), golpe.get_tipoNum()) * get_relacaoTipo(pokemon.get_tipo2(), golpe.get_tipoNum()); // Fórmula adaptada da geração 5 para frente que pode ser encontrada aqui: https://bulbapedia.bulbagarden.net/wiki/Damage
    
    if(golpe.get_tipoNum() == this->get_tipo1Num() || golpe.get_tipoNum() == this->get_tipo2Num()) // Confere se o golpe tem o mesmo tipo que o Pokémon, se estiver aumenta o dano em 50%
        dano *= 1.5;

    if(this->get_condicao() == 1) // Confere se o Pokémon está queimando, se estiver reduz o dano em 50%
        dano *= 0.5;

    return dano;
}

void Pokemon::ativar_item(Item &item) {
if (item.get_ativo()) {
        item.aplicar_efeito(*this);  // Aplica o efeito do item ao Pokémon atual
    }
}
