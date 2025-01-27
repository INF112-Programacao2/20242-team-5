#include "Batalha.hpp"

Batalha::Batalha(Pokemon *pokemon1, Pokemon *pokemon2) : _pokemon1(pokemon1), _pokemon2(pokemon2), _turnoAtual(1) {}

// Método para determinar quem começa atacando
Pokemon *Batalha::determinarIniciativa() {
    if (_pokemon1->get_estatistica(5) > _pokemon2->get_estatistica(5)) {
        return _pokemon1;
    } else if (_pokemon1->get_estatistica(5) < _pokemon2->get_estatistica(5)) {
        return _pokemon2;
    } else {
        // Em caso de empate, escolher aleatoriamente
        return (rand() % 2 == 0) ? _pokemon1 : _pokemon2;
    }
}

void Batalha::iniciar() {
    std::cout << "Iniciando a batalha entre " << _pokemon1->get_nome() << " e " << _pokemon2->get_nome() << "!\n";

    Pokemon *atacante = determinarIniciativa();
    Pokemon *defensor = (atacante == _pokemon1) ? _pokemon2 : _pokemon1;

    while (true) {
        std::cout << "\nTurno " << _turnoAtual << ":\n";
        turno(atacante, defensor);

        // Verifica se o defensor foi derrotado
        if (verificaDerrota(defensor)) {
            std::cout << defensor->get_nome() << " foi derrotado!\n";
            std::cout << atacante->get_nome() << " venceu a batalha!\n";
            break;
        }

        // Troca os papéis de atacante e defensor
        std::swap(atacante, defensor);
        _turnoAtual++; // Incrementa o turno
    }
}

void Batalha::turno(Pokemon *atacante, Pokemon *defensor) {
    int indice = -1;
    int escolha = -1;

    // Ativando habilidades
    std::cout << atacante->get_nome() << " está atacando " << defensor->get_nome() << "!\n";
    if(_turnoAtual == 1){
        std::cout << atacante->get_nome() << " teve sua habilidade ativada\nDescrição: " << atacante->get_habilidade().get_descricao();
        atacante->get_habilidade().aplicar(*atacante);
        std::cout << defensor->get_nome() << " teve sua habilidade ativada\nDescrição: " << defensor->get_habilidade().get_descricao();
        defensor->get_habilidade().aplicar(*atacante); 
    }

    //Ativando Items
    if(_turnoAtual == 1){
        std::cout << atacante->get_nome() << " teve seu item ativado\nDescrição: " << atacante->get_item().get_descricao_item();
        atacante->get_item().aplicar_efeito(*atacante);
        std::cout << defensor->get_nome() << " teve seu item ativado\nDescrição: " << defensor->get_item().get_descricao_item();
        defensor->get_item().aplicar_efeito(*atacante); 
    }

    // Escolhendo Golpes
    do{
        for(int i = 0; i < 4; i++){
            std::cout << i + 1 << " - " << atacante->get_golpe(i).get_nome() << "\n" <<
            " Poder Base: " << atacante->get_golpe(i).get_poderBase() << "\n" <<
            " Precisão: " << atacante->get_golpe(i).get_precisao();
        }
        std::cout << "Escolha algum golpe acima com base no seu indice: ";
        std::cin >> escolha;
    } while(escolha < 0 || escolha > 4);

    // Calcula o dano causado
    Golpe golpe = atacante->get_golpe(escolha);
    float dano = atacante->calculaDano(golpe, *defensor);

    // Aplica o dano ao defensor
    int vidaAtual = defensor->get_estatistica(0);
    defensor->set_estatistica(0, std::max(0, vidaAtual - static_cast<int>(dano)));

    std::cout << defensor->get_nome() << " sofreu " << dano << " de dano. Vida atual: " << defensor->get_estatistica(0) << "\n";
}

bool Batalha::verificaDerrota(Pokemon *pokemon) {
    return pokemon->get_estatistica(0) <= 0;
}
