#include "Pokemon.hpp"


Pokemon::Pokemon(){
    _condicao = 0; // Começa sem condição
    for (int i = 0; i < 6; i++) {
        _estagios[i] = 0; // Começa com todos os estágios no 0
    }
}

std::string Pokemon::get_nome(){
    return _nome;
}

int Pokemon::get_id(){
    return _id;
}

float Pokemon::get_estatistica(int estatistica){ // Retorna uma das seis estatísticas do Pokémon
    return _estatisticas[estatistica];
}

float Pokemon::get_vidaAtual(){ // Retorna a vida atual do Pokémon
    return _vidaAtual;
}

float Pokemon::get_estagio(int estatistica){ // Retorna o estágio de uma das 6 estatísticas do Pokémon
    if(_estagios[estatistica] >= 0)
        return (2+_estagios[estatistica])/2;
    return 2/(2-_estagios[estatistica]);
}

Tipo* Pokemon::get_tipo1(){
    return &_tipo1;
}

Tipo* Pokemon::get_tipo2(){
    return &_tipo2;
}

int Pokemon::get_tipo1Num() { // Retorna o número do tipo 1 do Pokémon
    return _tipo1.get_numRep();
}

int Pokemon::get_tipo2Num() { // Retorna o número do tipo 2 do Pokémon
    return _tipo2.get_numRep();
}

float Pokemon::get_relacaoTipo(Tipo *tipo, int posicao){ // Retorna a relação entre dois tipos
    return tipo->get_relacao(tipo->get_numRep(), (posicao));
}

int Pokemon::get_condicao(){
    return _condicao;
}

int Pokemon::get_lista(int posicao){ // Retorna o número de um golpe da lista
    return _lista[posicao];
}

int Pokemon::get_golpe(int num){ // Retorna o número de um golpe escolhido
    return _golpes[num];
}

Habilidade &Pokemon::get_habilidade() {
    return *_habilidade;  // Retorna a habilidade para aplicar polimorfismo
}

Item &Pokemon::get_item() {
    return *_item;  // Retorna o item para aplicar polimorfismo
}



void Pokemon::set_nome(std::string nome) {
    _nome = nome;
}

void Pokemon::set_id(int id){
    if(id < 0)
        throw std::invalid_argument("Valor do id do pokémon inválido");
    _id = id;
}

void Pokemon::set_estatistica(int estatistica, float valor){ // Altera o valor de uma das seis estatísticas do Pokémon
    if((estatistica < 0 || estatistica > 6) || (valor < 0 && estatistica != 0))
        throw std::invalid_argument("Valor da estatística inválida ou valor inserido negativo");
     _estatisticas[estatistica] = valor;
}

void Pokemon::set_vidaAtual(float vidaAtual){// Altera a vida atual do Pokémon
    _vidaAtual = vidaAtual;
}

void Pokemon::set_estagio(int estatistica, float estagio) { // Altera o estágio de uma das estatísticas do Pokémon
    if(estagio >= -6 && estagio <= 6)
        _estagios[estatistica] = estagio;
}

void Pokemon::set_tipo1(Tipo *tipo){
    _tipo1 = *tipo;
}

void Pokemon::set_tipo2(Tipo *tipo){
    _tipo2 = *tipo;
}

void Pokemon::set_condicao(int condicao){ // Altera a condição do Pokémon
    _condicao = condicao;
}

void Pokemon::set_lista(int posicao, int num){ // Altera o número de um golpe da lista
    _lista[posicao] = num;
}

void Pokemon::set_golpe(int posicao, int num){ // Altera o número de um golpe da escolhido
    _golpes[posicao] = num;
}

void Pokemon::set_habilidade(Habilidade &habilidade) {
    _habilidade = &habilidade;  // Definindo a habilidade através de polimorfismo
}

void Pokemon::set_item(Item &item) {
    _item = &item;
}



float Pokemon::calculaDano(Golpe &golpe, Pokemon &pokemon){ // Calcula o dano que o Pokémon causará usando um golpe contra um Pokémon inimigo
    float dano;

    if(!golpe.is_especial() && golpe.get_poderBase() > 0) // Verifica se é físico ou especial
        dano = ((22 * golpe.get_poderBase() * ((this->get_estatistica(1)*this->get_estagio(1)) / (pokemon.get_estatistica(2)*pokemon.get_estagio(2))))/50 + 2) * get_relacaoTipo(pokemon.get_tipo1(), golpe.get_tipoNum()) * get_relacaoTipo(pokemon.get_tipo2(), golpe.get_tipoNum()); // Fórmula adaptada da geração 5 para frente que pode ser encontrada aqui: https://bulbapedia.bulbagarden.net/wiki/Damage
    else if(golpe.get_poderBase() >0)
        dano = ((22 * golpe.get_poderBase() * ((this->get_estatistica(3)*this->get_estagio(3)) / (pokemon.get_estatistica(4)*pokemon.get_estagio(4))))/50 + 2) * get_relacaoTipo(pokemon.get_tipo1(), golpe.get_tipoNum()) * get_relacaoTipo(pokemon.get_tipo2(), golpe.get_tipoNum()); // Fórmula adaptada da geração 5 para frente que pode ser encontrada aqui: https://bulbapedia.bulbagarden.net/wiki/Damage
    else
        dano = 0;
    
    if(golpe.get_tipoNum() == this->get_tipo1Num() || golpe.get_tipoNum() == this->get_tipo2Num()) // Confere se o golpe tem o mesmo tipo que o Pokémon, se tiver aumenta o dano em 50%
        dano *= 1.5;

    if(this->get_condicao() == 1) // Confere se o Pokémon está queimando, se estiver reduz o dano em 50%
        dano *= 0.5;

    return dano;
}

void Pokemon::atacarG(Pokemon* oponente, Golpe* golpe, int golpeEscolhido){ // Ataca o Pokémon inimigo com um golpe simples
    std::cout << std::endl << this->get_nome() << " irá usar " << golpe[this->get_golpe(golpeEscolhido)].get_nome() << " contra " << oponente->get_nome() << "!\n";

    if(rand()% 100 + 1 <= golpe[this->get_golpe(golpeEscolhido)].get_precisao()){ // Determinando se o golpe acertará
        std::cout << "Causou " << (int)this->calculaDano(golpe[this->get_golpe(golpeEscolhido)], *oponente) << " de dano!\n";
        oponente->set_vidaAtual(oponente->get_vidaAtual() - this->calculaDano(golpe[this->get_golpe(golpeEscolhido)], *oponente)); // Calcula o dano e altera a vida do inimigo
    }

    else
        std::cout << this->get_nome() << " errou!\n";
}

void Pokemon::atacarC(Pokemon* oponente, Condicional* condicionais, int golpeEscolhido){ // Ataca o Pokémon inimigo com um golpe modificador
    std::cout << std::endl << this->get_nome() << " irá usar " << condicionais[this->get_golpe(golpeEscolhido)-13].get_nome() << " contra " << oponente->get_nome() << "!\n";

    if(rand()% 100 + 1 <= condicionais[this->get_golpe(golpeEscolhido)-13].get_precisao()){ // Determinando se o golpe acertará
        if(condicionais[this->get_golpe(golpeEscolhido)-13].get_poderBase() != 0){ // Verifica se o golpe causa dano e pula o cálculo se não causar
            std::cout << "Causou " << (int)this->calculaDano(condicionais[this->get_golpe(golpeEscolhido)-13], *oponente) << " de dano!\n"; 
            oponente->set_vidaAtual(oponente->get_vidaAtual() - this->calculaDano(condicionais[this->get_golpe(golpeEscolhido)-13], *oponente)); // Calcula o dano e altera a vida do inimigo
        }

        if(rand()% 100 + 1 <= condicionais[this->get_golpe(golpeEscolhido)-13].get_chance()){ // Determinando se causará a condição
            oponente->set_condicao(condicionais[this->get_golpe(golpeEscolhido)-13].get_condicao()); // Aplica a condição
            std::cout << oponente->get_nome() << " foi ";
            switch(condicionais[this->get_golpe(golpeEscolhido)-13].get_condicao()){ // Verifica qual condição foi aplicada para escrever
                case 1: std::cout << "queimado!\n"; break; case 2: std::cout << "paralisado!\n"; break; case 3: std::cout << "envenenado!\n"; break;
            }
        }
    }

    else
        std::cout << this->get_nome() << " errou!\n";
}

void Pokemon::atacarM(Pokemon* oponente, ModificaEst* modificaests, int golpeEscolhido){ // Ataca o Pokémon inimigo com um golpe condicional
    std::cout << std::endl << this->get_nome() << " irá usar " << modificaests[this->get_golpe(golpeEscolhido)-24].get_nome() << " contra " << oponente->get_nome() << "!\n";

    if(rand()% 100 + 1 <= modificaests[this->get_golpe(golpeEscolhido)-24].get_precisao()){ // Determinando se o golpe acertará
        if(modificaests[this->get_golpe(golpeEscolhido)-24].get_poderBase() != 0){ // Verifica se o golpe causa dano e pula o cálculo se não causar
            std::cout << "Causou " << (int)this->calculaDano(modificaests[this->get_golpe(golpeEscolhido)-24], *oponente) << " de dano!\n";
            oponente->set_vidaAtual(oponente->get_vidaAtual() - this->calculaDano(modificaests[this->get_golpe(golpeEscolhido)-24], *oponente)); // Calcula o dano e altera a vida do inimigo
        }

        if(rand()% 100 + 1 <= modificaests[this->get_golpe(golpeEscolhido)-24].get_chance()){ // Determinando se modificará a estatística
            if(modificaests[this->get_golpe(golpeEscolhido)-24].is_autoAlvo()){ // Verifica se afeta o próprio usuário
                for(int i=1; i<6; i++) // Começa do 1 porque vida não pode ser alterada com estágios
                    if(modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i) != 0){ // Verifica quais estatísticas são afetadas
                        this->set_estagio(i, this->get_estagio(i) + modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i)); // Adiciona os estágios ao usuário
                        switch(i){ // Verifica qual estatística foi alterada para escrever
                            case 1: std::cout << "Ataque"; break; case 2: std::cout << "Defesa"; break; case 3: std::cout << "Ataque Especial"; break; case 4: std::cout << "Defesa Especial"; break; case 5: std::cout << "Velocidade"; break;
                        }
                        std::cout << " de " << this->get_nome() << " alterou em " << modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i) << " estágios!\n";
                    }
            }

            else
                for(int i=1; i<6; i++) // Começa do 1 porque vida não pode ser alterada com estágios
                    if(modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i) != 0){ // Verifica quais estatísticas são afetadas
                        this->set_estagio(i, oponente->get_estagio(i) + modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i)); // Adiciona os estágios ao oponente
                        switch(i){ // Verifica qual estatística foi alterada para escrever
                            case 1: std::cout << "Ataque"; break; case 2: std::cout << "Defesa"; break; case 3: std::cout << "Ataque Especial"; break; case 4: std::cout << "Defesa Especial"; break; case 5: std::cout << "Velocidade"; break;
                        }
                        std::cout << " de " << oponente->get_nome() << " alterou em " << modificaests[this->get_golpe(golpeEscolhido)-24].get_estatisticaAfetada(i) << " estágios!\n";
                    }
        }
    }

    else
        std::cout << this->get_nome() << " errou!\n";
}