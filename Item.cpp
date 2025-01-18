#include "Item.hpp"

Item::Item(std::string nome_item, std::string descricao, bool ativo)
    : _nome_item(nome_item), _descricao(descricao), _ativo(ativo) {}

std::string Item::get_nome_item() const {
    return _nome_item;
}

bool Item::get_ativo() const {
    return _ativo;
}

void Item::aplicar_efeito(Pokemon &pokemon) {
    if(_nome_item == "X Attack") {
        pokemon.set_estagio(1, pokemon.get_estagio(1) + 1);  // índice 1 é o ataque
    } else if(_nome_item == "X Defense"){
        pokemon.set_estagio(2, pokemon.get_estagio(2) + 1);
    } else if(_nome_item == "X Speed"){
        pokemon.set_estagio(5, pokemon.get_estagio(5) + 1);
    } else if(_nome_item == "Deep Sea Tooth"){
        pokemon.set_estagio(3, pokemon.get_estagio(3) + 1);
    } else if(_nome_item ==  "Deep Sea Scale"){
        pokemon.set_estagio(4, pokemon.get_estagio(4) + 1);
    } if (_nome_item == "Berserk Band" && pokemon.get_estatistica(0) <= vidaMaxima / 2) {
        pokemon.set_estagio(1, pokemon.get_estagio(1) + 2); 
    } else if (_nome_item == "Endure Scarf" && pokemon.get_estatistica(0) < vidaMaxima / 4) {
        pokemon.set_estagio(2, pokemon.get_estagio(2) + 2); 
    } else if (_nome_item == "Oran Berry" && pokemon.get_estatistica(0) < vidaMaxima / 2) {
        int novaVida = pokemon.get_estatistica(0) + 20;  
        pokemon.set_estatistica(0, novaVida);   //função a ser criada
        std::cout << pokemon.get_nome() << " consumiu a Oran Berry e recuperou 20 de vida!\n";
    }
}
