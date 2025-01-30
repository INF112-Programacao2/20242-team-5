#include "Habilidades.hpp"
#include "Items.hpp"
#include "Treinador.hpp"
#include <fstream>
#include <stdexcept>

int main(){
    // Vetor de Habilidades utilizaveis
    std::vector<Habilidade*> habilidades;
    habilidades.push_back(new Cura());
    habilidades.push_back(new AumentarAgressividade());
    habilidades.push_back(new AumentarDefesa());
    habilidades.push_back(new VelocidadeAumentada());

    //Vetor de Itens utilizaveis
    std::vector<Item*> itens;
    itens.push_back(new XAttack());
    itens.push_back(new XDefense());
    itens.push_back(new XSpeed());
    itens.push_back(new DeepSeaScale());

    int num;
    std::string nome;
    std::ifstream entrada("tipos.txt"); // Entrada dos tipos

    int tamanhoT;
    entrada >> tamanhoT;
    Tipo* tipos = new Tipo[tamanhoT]; // Vetor para os tipos
    for(int i=0; i<tamanhoT; i++){ // Lendo os tipos do arquivo
        entrada >> nome;
        tipos[i].set_nome(nome);
        float n;
        entrada >> n;
        tipos[i].set_numRep(n);
        for(int j=0; j<tamanhoT; j++){
            entrada >> n;
            tipos[0].set_relacao(n, i, j);
        }
    }

    entrada.close();
    entrada.open("golpes.txt"); // Entrada dos golpes

    Golpe* golpes; // Ponteiro para um vetor de golpes simples
    Condicional* condicionais; // Ponteiro para um vetor de golpes condicionais
    ModificaEst* modificaests; // Ponteiro para um vetor de golpes modificadores

    int tamanhoG; // Tamanho do vetor de golpes simples
    entrada >> tamanhoG;
    golpes = new Golpe[tamanhoG];
    for(int i=0; i<tamanhoG; i++){ // Leitura dos golpes simples
        entrada >> nome;
        golpes[i].set_nome(nome);
        entrada >> num;
        golpes[i].set_id(num);
        entrada >> num;
        golpes[i].set_poderBase(num);
        entrada >> num;
        golpes[i].set_precisao(num);
        entrada >> num;
        golpes[i].set_tipo(&tipos[num]);
        entrada >> num;
        golpes[i].set_especial(num);
    }

    int tamanhoC; // Tamanho do vetor de golpes condicionais
    entrada >> tamanhoC;
    condicionais = new Condicional[tamanhoC];
    for(int i=0; i<tamanhoC; i++){ // Leitura dos golpes condicionais
        entrada >> nome;
        condicionais[i].set_nome(nome);
        entrada >> num;
        condicionais[i].set_id(num);
        entrada >> num;
        condicionais[i].set_poderBase(num);
        entrada >> num;
        condicionais[i].set_precisao(num);
        entrada >> num;
        condicionais[i].set_tipo(&tipos[num]);
        entrada >> num;
        condicionais[i].set_especial(num);
        entrada >> num;
        condicionais[i].set_condicao(num);
        entrada >> num;
        condicionais[i].set_chance(num);
    }

    int tamanhoM; // Tamanho do vetor de golpes modificadores
    entrada >> tamanhoM;
    modificaests = new ModificaEst[tamanhoM];
    for(int i=0; i<tamanhoM; i++){ // Leitura dos golpes modificadores
        entrada >> nome;
        modificaests[i].set_nome(nome);
        entrada >> num;
        modificaests[i].set_id(num);
        entrada >> num;
        modificaests[i].set_poderBase(num);
        entrada >> num;
        modificaests[i].set_precisao(num);
        entrada >> num;
        modificaests[i].set_tipo(&tipos[num]);
        entrada >> num;
        modificaests[i].set_especial(num);
        for(int j=1; j<6; j++){
            entrada >> num;
            modificaests[i].set_estatisticaAfetada(j, num);
        }
        entrada >> num;
        modificaests[i].set_chance(num);
        entrada >> num;
        modificaests[i].set_autoAlvo(num);
    }

    entrada.close();
    entrada.open("pokemon.txt"); // Entrada dos Pokémon

    Pokemon* pokemon; // Ponteiro para um vetor de Pokémon
    int tamanhoP; // Tamanho do vetor de Pokémon
    entrada >> tamanhoP;
    pokemon = new Pokemon[tamanhoP];
    for(int i=0; i<tamanhoP; i++){ // Leitura dos Pokémon
        entrada >> nome;
        pokemon[i].set_nome(nome);
        entrada >> num;
        pokemon[i].set_id(num);
        float n;
        for(int j=0; j<6; j++){
            entrada >> n;
            pokemon[i].set_estatistica(j, n);
        }
        pokemon[i].set_vidaAtual(pokemon[i].get_estatistica(0));
        entrada >> num;
        pokemon[i].set_tipo1(&tipos[num]);
        entrada >> num;
        pokemon[i].set_tipo2(&tipos[num]);
        for(int j=0; j<8; j++){
            entrada >> num;
            pokemon[i].set_lista(j, num);
        }
    }

    entrada.close();

    std::cout << "Nome do treinador 1: "; // Processo de inicialização do treinador 1
    std::cin >> nome;
    std::cout << std::endl << nome << ", escolha um Pokémon:\n\n";

    for(int i=0; i<tamanhoP; i++){ // Exibição das informações de cada Pokémon
        std::cout << pokemon[i].get_nome() << std::endl << "ID: " << pokemon[i].get_id() << std::endl << tipos[pokemon[i].get_tipo1Num()].get_nome() << " " << tipos[pokemon[i].get_tipo2Num()].get_nome() << std::endl; // Nome, ID e tipos

        std::cout << "HP ATK DEF SPATK SPDEF SPE\n";
        for(int j=0; j<6; j++)
            std::cout << pokemon[i].get_estatistica(j) << " "; // Estatísticas
        std::cout << std::endl;
    
        for(int j=0; j<8; j++){ // Exibição dos golpes, determinando se são modificadores, condicionais ou simples baseado no número
            if(pokemon[i].get_lista(j) > (tamanhoG+tamanhoC)-1) // (tamanhoG+tamanhoC) corresponde a quantidade de golpes antes dos modificadores, -1 aqui para levar em conta o 0
                std::cout << modificaests[pokemon[i].get_lista(j)-(tamanhoG+tamanhoC)].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome

            else if(pokemon[i].get_lista(j) > tamanhoG-1) // tamanhoG corresponde a quantidade de golpes antes dos condicionais, -1 aqui para levar em conta o 0
                std::cout << condicionais[pokemon[i].get_lista(j)-tamanhoG].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome
            
            else
                std::cout << golpes[pokemon[i].get_lista(j)].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    int pokemon1;
    // Tratamento de entrada
    while (true) {
        try {
            std::cout << "Insira o ID do seu Pokémon escolhido: ";
            std::cin >> pokemon1;

            if(std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if (pokemon1 < 1 || pokemon1 > tamanhoP) {
                throw std::out_of_range("Número fora do intervalo permitido!");
            }
            break; // Sai do loop se tudo estiver certo
        } catch (const std::exception &e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }
    pokemon1--; // Arrumando para considerar o 0

    Treinador treinador1(nome, &pokemon[pokemon1]); // Inicialização do treinador 1

    std::cout << "\nEscolha quatro dos golpes que esse Pokémon pode aprender: \n";

    for(int i=0; i<8; i++){ // Exibição dos golpes na lista do Pokémon, determinando se são modificadores, condicionais ou simples baseado no número
        if(pokemon[pokemon1].get_lista(i) > (tamanhoG+tamanhoC)-1){ // (tamanhoG+tamanhoC) corresponde a quantidade de golpes antes dos modificadores, -1 aqui para levar em conta o 0
            std::cout << i+1 << ": " << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_nome() << std::endl << tipos[modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_poderBase() << " Precisão: " << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_precisao() << std::endl; // Nome, tipo, dano e precisão

            if(modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].is_autoAlvo()) // Determina se afeta o próprio usuário
                std::cout << "Este golpe tem " << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_chance() << "% de chance de afetar as estatísticas do próprio Pokémon, em estágios: \nATK DEF SPATK SPDEF SPE\n"; // Explicação da chance e de quais estatísticas podem ser afetadas

            else
                std::cout << "Este golpe tem " << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_chance() << "% de chance de afetar as estatísticas do Pokémon inimigo, em estágios: \nATK DEF SPATK SPDEF SPE\n"; // Explicação da chance e de quais estatísticas podem ser afetadas
            
            for(int j=1; j<6; j++)
                std::cout << modificaests[pokemon[pokemon1].get_lista(i)-(tamanhoG+tamanhoC)].get_estatisticaAfetada(j) << " "; // Exibe as estatísticas

            std::cout << std::endl;
        }
        else if(pokemon[pokemon1].get_lista(i) > tamanhoG-1){ // tamanhoG corresponde a quantidade de golpes antes dos condicionais, -1 aqui para levar em conta o 0
            std::cout << i+1 << ": " << condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_nome() << std::endl << tipos[condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_tipoNum()].get_nome() << std::endl << "Poder base: " << condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_poderBase() << " Precisão: " << condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_precisao() << std::endl; // Nome, tipo, dano e precisão
            
            std::cout << "Este golpe tem " << condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_chance() << "% de chance de aplicar a condição "; // Explicação da chance e de qual condição o golpe aplica
            switch(condicionais[pokemon[pokemon1].get_lista(i)-tamanhoG].get_condicao()){
                case 1: std::cout << "queimadura\n"; break; case 2: std::cout << "paralisia\n"; break; case 3: std::cout << "veneno\n"; break; // Verifica qual condição pode ser aplicada para escrever
            }
        }
        else
            std::cout << i+1 << ": " << golpes[pokemon[pokemon1].get_lista(i)].get_nome() << std::endl << tipos[golpes[pokemon[pokemon1].get_lista(i)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << golpes[pokemon[pokemon1].get_lista(i)].get_poderBase() << " Precisão: " << golpes[pokemon[pokemon1].get_lista(i)].get_precisao() << std::endl; // Nome, tipo, dano e precisão

        std::cout << std::endl;
    }

    std::cout << "Insira os indices dos 4 golpes escolhidos (separados): ";
    for(int i=0; i<4; i++){ // Seleção de golpes
        std::cin >> num;
        num--;
        
        treinador1.set_golpePokemon(i, treinador1.get_listaPokemon(num));
    }

    int escolha_habilidade; // Escolhe o Indice da habilidade
    int escolha_item;       // Escolhe o Indice do item

    // Escolha da habilidade
    std::cout << "\nEscolha uma habilidade abaixo:\n";
    for(size_t i = 0; i < habilidades.size(); i++){     // Escreva as habilidade disponiveis
        std::cout << i+1 << " - " << habilidades[i]->get_nome() << ", " << habilidades[i]->get_descricao() << std::endl;
    }
    
    // Tratamento de entrada
    while (true) {
        try {
            std::cout << "Insira o índice da habilidade: ";
            std::cin >> escolha_habilidade;
            if(std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if(escolha_habilidade < 1 || static_cast<std::size_t>(escolha_habilidade) > habilidades.size()) {
                throw std::out_of_range("Índice para escolha da habilidade inválido");
            }
            // Ajustando o índice para base 0 
            treinador1.get_pokemonPonteiro().set_habilidade(*habilidades[escolha_habilidade - 1]);
            break; 
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }

    // Item
    std::cout << "Escolha um item abaixo:\n";
    for(size_t i = 0; i < itens.size(); i++){   // Escreve os itens diponiveis
        std::cout << i+1 << " - " << itens[i]->get_nome() << ", " << itens[i]->get_descricao() << std::endl;
    }

    // Tratamento de entrada
    while (true) {
        try {
            std::cout << "Insira o índice do item: ";
            std::cin >> escolha_item;
            if (std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if (escolha_item < 1 || static_cast<std::size_t>(escolha_item) > itens.size()) {
                throw std::out_of_range("Índice para escolha do item inválido");
            }
            // Ajustando o índice para base 0
            treinador1.get_pokemonPonteiro().set_item(*itens[escolha_item - 1]);
            break; 
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }

    std::cout << "Nome do treinador 2: "; // Processo de inicialização do treinador 2
    std::cin >> nome;
    std::cout << std::endl << nome << ", escolha um Pokémon:\n\n";

    for(int i=0; i<tamanhoP; i++){ // Exibição das informações de cada Pokémon
        std::cout << pokemon[i].get_nome() << std::endl << "ID: " << pokemon[i].get_id() << std::endl << tipos[pokemon[i].get_tipo1Num()].get_nome() << " " << tipos[pokemon[i].get_tipo2Num()].get_nome() << std::endl; //Nome, ID e tipos

        std::cout << "HP ATK DEF SPATK SPDEF SPE\n";
        for(int j=0; j<6; j++)
            std::cout << pokemon[i].get_estatistica(j) << " "; // Estatísticas
        std::cout << std::endl;

        for(int j=0; j<8; j++){ // Exibição dos golpes, determinando se são modificadores, condicionais ou simples baseado no número
            if(pokemon[i].get_lista(j) > (tamanhoG+tamanhoC)-1) // (tamanhoG+tamanhoC) corresponde a quantidade de golpes antes dos modificadores, -1 aqui para levar em conta o 0
                std::cout << modificaests[pokemon[i].get_lista(j)-(tamanhoG+tamanhoC)].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome

            else if(pokemon[i].get_lista(j) > tamanhoG-1) // tamanhoG corresponde a quantidade de golpes antes dos condicionais, -1 aqui para levar em conta o 0
                std::cout << condicionais[pokemon[i].get_lista(j)-tamanhoG].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome

            else
                std::cout << golpes[pokemon[i].get_lista(j)].get_nome() << " "; // Acessa o número dos golpes na lista do Pokémon e usa para acessar o golpe no vetor e exibir o nome
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    int pokemon2;
    while (true) {
        try {
            std::cout << "Insira o ID do seu Pokémon escolhido: ";
            std::cin >> pokemon2;

            if (std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if (pokemon2 < 1 || pokemon2 > tamanhoP) {
                throw std::out_of_range("Número fora do intervalo permitido!");
            }
            break;  // Sai do loop se tudo estiver certo
        } catch (const std::exception &e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }
    pokemon2--; // Arrumando para considerar o 0

    Treinador treinador2(nome, &pokemon[pokemon2]); // Inicialização do treinador 2

    std::cout << "\nEscolha quatro dos golpes que esse Pokémon pode aprender: \n";

    for(int i=0; i<8; i++){ // Exibição dos golpes na lista do Pokémon, determinando se são modificadores, condicionais ou simples baseado no número
        if(pokemon[pokemon2].get_lista(i) > (tamanhoG+tamanhoC)-1){ // (tamanhoG+tamanhoC) corresponde a quantidade de golpes antes dos modificadores, -1 aqui para levar em conta o 0
            std::cout << i+1 << ": " << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_nome() << std::endl << tipos[modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_poderBase() << " Precisão: " << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_precisao() << std::endl; // Nome, tipo, dano e precisão

            if(modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].is_autoAlvo()) // Determina se afeta o próprio usuário
                std::cout << "Este golpe tem " << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_chance() << "% de chance de afetar as estatísticas do próprio Pokémon, em estágios: \nATK DEF SPATK SPDEF SPE\n"; // Explicação da chance e de quais estatísticas podem ser afetadas

            else
                std::cout << "Este golpe tem " << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_chance() << "% de chance de afetar as estatísticas do Pokémon inimigo, em estágios: \nATK DEF SPATK SPDEF SPE\n"; // Explicação da chance e de quais estatísticas podem ser afetadas

            for(int j=1; j<6; j++)
                std::cout << modificaests[pokemon[pokemon2].get_lista(i)-(tamanhoG+tamanhoC)].get_estatisticaAfetada(j) << " "; // Exibe as estatísticas

            std::cout << std::endl;
        }

        else if(pokemon[pokemon2].get_lista(i) > tamanhoG-1){ // tamanhoG corresponde a quantidade de golpes antes dos condicionais, -1 aqui para levar em conta o 0
            std::cout << i+1 << ": " << condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_nome() << std::endl << tipos[condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_tipoNum()].get_nome() << std::endl << "Poder base: " << condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_poderBase() << " Precisão: " << condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_precisao() << std::endl; // Nome, tipo, dano e precisão

            std::cout << "Este golpe tem " << condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_chance() << "% de chance de aplicar a condição "; // Explicação da chance e de qual condição o golpe aplica
            switch(condicionais[pokemon[pokemon2].get_lista(i)-tamanhoG].get_condicao()){ 
                case 1: std::cout << "queimadura\n"; break; case 2: std::cout << "paralisia\n"; break; case 3: std::cout << "veneno\n"; break; // Verifica qual condição pode ser aplicada para escrever
            }
        }
        else
            std::cout << i+1 << ": " << golpes[pokemon[pokemon2].get_lista(i)].get_nome() << std::endl << tipos[golpes[pokemon[pokemon2].get_lista(i)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << golpes[pokemon[pokemon2].get_lista(i)].get_poderBase() << " Precisão: " << golpes[pokemon[pokemon2].get_lista(i)].get_precisao() << std::endl; // Nome, tipo, dano e precisão

        std::cout << std::endl;
    }
    std::cout << "Insira os indices dos 4 golpes escolhidos (separados): ";
    for(int i=0; i<4; i++){ // Seleção de golpes
        std::cin >> num;
        num--;

        treinador2.set_golpePokemon(i, treinador2.get_listaPokemon(num));
    }

    // Habilidade
    std::cout << "\nEscolha uma habilidade abaixo:\n";
    for(size_t i = 0; i < habilidades.size(); i++){ // Escreve as habilidades diponiveis
        std::cout << i+1 << " - " << habilidades[i]->get_nome() << ": " << habilidades[i]->get_descricao() << std::endl;
    }
    // Tratamento de entrada
    while (true) {
        try {
            std::cout << "Insira o índice da habilidade: ";
            std::cin >> escolha_habilidade;
            if (std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if (escolha_habilidade < 1 || static_cast<std::size_t>(escolha_habilidade) > habilidades.size()) {
                throw std::out_of_range("Índice para escolha da habilidade inválido");
            }
            // Ajustando o índice para base 0 
            treinador2.get_pokemonPonteiro().set_habilidade(*habilidades[escolha_habilidade - 1]);
            break; 
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }

    // Item
    std::cout << "Escolha um item abaixo:\n";   
    for(size_t i = 0; i < itens.size(); i++){   // Escreve os itens disponiveis
        std::cout << i+1 << " - " << itens[i]->get_nome() << ": " << itens[i]->get_descricao() << std::endl;
    }
    // Tratamento de entrada
    while (true) {
        try {
            std::cout << "Insira o índice do item: ";
            std::cin >> escolha_item;
            if (std::cin.fail()) {
                throw std::invalid_argument("Entrada inválida! Digite um número.");
            }
            if (escolha_item < 1 || static_cast<std::size_t>(escolha_item) > itens.size()) {
                throw std::out_of_range("Índice para escolha do item inválido");
            }
            // Ajustando o índice para base 0
            treinador2.get_pokemonPonteiro().set_item(*itens[escolha_item - 1]);
            break; 
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << "\nTente novamente.\n";
        }
    }

    std::cout << std::endl;
    std::cout << "Iniciando a batalha agora!\n";

    Pokemon pokemon_1 = treinador1.get_pokemon(), pokemon_2 = treinador2.get_pokemon();
    int turno = 1;

    while(true){
        std::cout << "\nTurno " << turno << std::endl << std::endl; // Contador de turnos

        //ATIVANDO HABILIDADE
        if(turno == 1){
            treinador1.get_pokemonPonteiro().get_habilidade().aplicar(treinador1.get_pokemonPonteiro());
            treinador2.get_pokemonPonteiro().get_habilidade().aplicar(treinador2.get_pokemonPonteiro());
        } else {
            if(treinador1.get_pokemonPonteiro().get_habilidade().get_nome() ==  "Cura")
                treinador1.get_pokemonPonteiro().get_habilidade().aplicar(treinador1.get_pokemonPonteiro());
            if(treinador2.get_pokemonPonteiro().get_habilidade().get_nome() ==  "Cura")
                treinador2.get_pokemonPonteiro().get_habilidade().aplicar(treinador2.get_pokemonPonteiro());
        }
        std::cout << "\n";

        //ATIVANDO ITENS
        if(turno == 1){
            std::cout << treinador1.get_nome();
            treinador1.get_pokemonPonteiro().get_item().aplicar_efeito(treinador1.get_pokemonPonteiro());
            std::cout << treinador2.get_nome();
            treinador2.get_pokemonPonteiro().get_item().aplicar_efeito(treinador2.get_pokemonPonteiro());
        }
        std::cout << "\n";

        std::cout << pokemon_1.get_nome() << " tem " << (int)pokemon_1.get_vidaAtual() << " de vida\n"; // Vida do primeiro Pokémon
        std::cout << pokemon_2.get_nome() << " tem " << (int)pokemon_2.get_vidaAtual() << " de vida\n\n"; // Vida do segundo Pokémon

        std::cout << treinador1.get_nome() << ", escolha seu golpe\n\n";

        for(int i=0; i<4; i++){ // Exibição dos golpes
            if(pokemon_1.get_golpe(i) > (tamanhoG+tamanhoC)-1){ // (tamanhoG+tamanhoC) corresponde a quantidade de golpes antes dos modificadores, -1 aqui para levar em conta o 0
                std::cout << i+1 << ": " << modificaests[pokemon_1.get_golpe(i)-(tamanhoG+tamanhoC)].get_nome() << std::endl << tipos[modificaests[pokemon_1.get_golpe(i)-(tamanhoG+tamanhoC)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << modificaests[pokemon_1.get_golpe(i)-(tamanhoG+tamanhoC)].get_poderBase() << " Precisão: " << modificaests[pokemon_1.get_golpe(i)-(tamanhoG+tamanhoC)].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }
            else if(pokemon_1.get_golpe(i) > tamanhoG-1){ // tamanhoG corresponde a quantidade de golpes antes dos condicionais, -1 aqui para levar em conta o 0
                std::cout << i+1 << ": " << condicionais[pokemon_1.get_golpe(i)-tamanhoG].get_nome() << std::endl << tipos[condicionais[pokemon_1.get_golpe(i)-tamanhoG].get_tipoNum()].get_nome() << std::endl << "Poder base: " << condicionais[pokemon_1.get_golpe(i)-tamanhoG].get_poderBase() << " Precisão: " << condicionais[pokemon_1.get_golpe(i)-tamanhoG].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }
            else{
                std::cout << i+1 << ": " << golpes[pokemon_1.get_golpe(i)].get_nome() << std::endl << tipos[golpes[pokemon_1.get_golpe(i)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << golpes[pokemon_1.get_golpe(i)].get_poderBase() << " Precisão: " << golpes[pokemon_1.get_golpe(i)].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }

            std::cout << std::endl;
        }

        int golpe1; // Seleção de golpe
        std::cin >> golpe1;
        golpe1--; // Ajuste para o 0

        std::cout << treinador2.get_nome() << ", escolha seu golpe\n\n";

        for(int i=0; i<4; i++){
            if(pokemon_2.get_golpe(i) > (tamanhoG+tamanhoC)-1){
                std::cout << i+1 << ": " << modificaests[pokemon_2.get_golpe(i)-(tamanhoG+tamanhoC)].get_nome() << std::endl << tipos[modificaests[pokemon_2.get_golpe(i)-(tamanhoG+tamanhoC)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << modificaests[pokemon_2.get_golpe(i)-(tamanhoG+tamanhoC)].get_poderBase() << " Precisão: " << modificaests[treinador2.get_golpePokemon(i)-(tamanhoG+tamanhoC)].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }
            else if(pokemon_2.get_golpe(i) > tamanhoG-1){
                std::cout << i+1 << ": " << condicionais[pokemon_2.get_golpe(i)-tamanhoG].get_nome() << std::endl << tipos[condicionais[pokemon_2.get_golpe(i)-tamanhoG].get_tipoNum()].get_nome() << std::endl << "Poder base: " << condicionais[pokemon_2.get_golpe(i)-tamanhoG].get_poderBase() << " Precisão: " << condicionais[pokemon_2.get_golpe(i)-tamanhoG].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }
            else{
                std::cout << i+1 << ": " << golpes[pokemon_2.get_golpe(i)].get_nome() << std::endl << tipos[golpes[pokemon_2.get_golpe(i)].get_tipoNum()].get_nome() << std::endl << "Poder base: " << golpes[pokemon_2.get_golpe(i)].get_poderBase() << " Precisão: " << golpes[pokemon_2.get_golpe(i)].get_precisao() << std::endl; // Nome, tipo, poder e precisão
            }

            std::cout << std::endl;
        }

        int golpe2; // Seleção de golpe
        std::cin >> golpe2;
        golpe2--; // Ajuste para o 0

        if((pokemon_1.get_condicao() != 2 && pokemon_2.get_condicao() !=3 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5) > pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5)) || 
        (pokemon_2.get_condicao() == 2 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5) > pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5)/2) ||
        (pokemon_1.get_condicao() == 2 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5)/2 > pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5))){ // Confere se o pokemon_1 é mais rápido levando em consideração paralisia
            // pokemon_1 move primeiro
            if(pokemon_1.get_golpe(golpe1) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                pokemon_1.atacarM(&pokemon_2, modificaests, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else if(pokemon_1.get_golpe(golpe1) > tamanhoG-1){ // Confere se o golpe é condicional
                pokemon_1.atacarC(&pokemon_2, condicionais, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else{ // Caso seja golpe simples
                pokemon_1.atacarG(&pokemon_2, golpes, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            // pokemon_2 move segundo
            if(pokemon_2.get_golpe(golpe2) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                pokemon_2.atacarM(&pokemon_1, modificaests, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else if(pokemon_2.get_golpe(golpe2) > tamanhoG-1){ // Confere se o golpe é condicional
                pokemon_2.atacarC(&pokemon_1, condicionais, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else{ // Caso seja golpe simples
                pokemon_2.atacarG(&pokemon_1, golpes, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }
        }

        else if((pokemon_1.get_condicao() != 2 && pokemon_2.get_condicao() != 3 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5) < pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5)) || 
        (pokemon_2.get_condicao() == 2 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5) < pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5)/2) ||
        (pokemon_1.get_condicao() == 2 && pokemon_1.get_estatistica(5)*pokemon_1.get_estagio(5)/2 < pokemon_2.get_estatistica(5)*pokemon_2.get_estagio(5))){ // Confere se o pokemon_2 é mais rápido levando em consideração paralisia
            if(pokemon_2.get_golpe(golpe2) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                pokemon_2.atacarM(&pokemon_1, modificaests, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else if(pokemon_2.get_golpe(golpe2) > tamanhoG-1){ // Confere se o golpe é condicional
                pokemon_2.atacarC(&pokemon_1, condicionais, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else{ // Caso seja golpe simples
                pokemon_2.atacarG(&pokemon_1, golpes, golpe2);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }
             
            if(pokemon_1.get_golpe(golpe1) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                pokemon_1.atacarM(&pokemon_2, modificaests, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else if(pokemon_1.get_golpe(golpe1) > tamanhoG-1){ // Confere se o golpe é condicional
                pokemon_1.atacarC(&pokemon_2, condicionais, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }

            else{ // Caso seja golpe simples
                pokemon_1.atacarG(&pokemon_2, golpes, golpe1);
                if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                    break;
            }
        }

        else{
            if(rand() % 2 == 0){ // Caso as velocidades sejam iguais, quem vai primeiro é decidido na sorte
                if(pokemon_1.get_golpe(golpe1) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                    pokemon_1.atacarM(&pokemon_2, modificaests, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else if(pokemon_1.get_golpe(golpe1) > tamanhoG-1){ // Confere se o golpe é condicional
                    pokemon_1.atacarC(&pokemon_2, condicionais, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }
                
                else{ // Caso seja golpe simples
                    pokemon_1.atacarG(&pokemon_2, golpes, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                if(pokemon_2.get_golpe(golpe2) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                    pokemon_2.atacarM(&pokemon_1, modificaests, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else if(pokemon_2.get_golpe(golpe2) > tamanhoG-1){ // Confere se o golpe é condicional
                    pokemon_2.atacarC(&pokemon_1, condicionais, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else{ // Caso seja golpe simples
                    pokemon_2.atacarG(&pokemon_1, golpes, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }
            }
            else{
                if(pokemon_2.get_golpe(golpe2) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                    pokemon_2.atacarM(&pokemon_1, modificaests, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else if(pokemon_2.get_golpe(golpe2) > tamanhoG-1){ // Confere se o golpe é condicional
                    pokemon_2.atacarC(&pokemon_1, condicionais, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else{ // Caso seja golpe simples
                    pokemon_2.atacarG(&pokemon_1, golpes, golpe2);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                if(pokemon_1.get_golpe(golpe1) > (tamanhoG+tamanhoC)-1){ // Confere se o golpe é modificador
                    pokemon_1.atacarM(&pokemon_2, modificaests, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else if(pokemon_1.get_golpe(golpe1) > tamanhoG-1){ // Confere se o golpe é condicional
                    pokemon_1.atacarC(&pokemon_2, condicionais, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }

                else{ // Caso seja golpe simples
                    pokemon_1.atacarG(&pokemon_2, golpes, golpe1);
                    if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
                        break;
                }
            }
        }

        switch(pokemon_1.get_condicao()){ // Verifica se o pokemon_1 sofrerá dano de condição
            case 1: std::cout << pokemon_1.get_nome() << " sofreu " << (int)pokemon_1.get_estatistica(0)/16 << " de dano pela queimadura!\n"; pokemon_1.set_vidaAtual(pokemon_1.get_vidaAtual() - pokemon_1.get_estatistica(0)/16); break; // Aplica o dano da queimadura
            case 3: std::cout << pokemon_1.get_nome() << " sofreu " << (int)pokemon_1.get_estatistica(0)/8 << " de dano pelo envenenamento!\n"; pokemon_1.set_vidaAtual(pokemon_1.get_vidaAtual() - pokemon_1.get_estatistica(0)/8); break; // Aplica o dano do envenenamento
        }

        switch(pokemon_2.get_condicao()){ // Verifica se o pokemon_2 sofrerá dano de condição
            case 1: std::cout << pokemon_2.get_nome() << " sofreu " << (int)pokemon_2.get_estatistica(0)/16 << " de dano pela queimadura!\n"; pokemon_2.set_vidaAtual(pokemon_2.get_vidaAtual() - pokemon_2.get_estatistica(0)/16); break; // Aplica o dano da queimadura
            case 3: std::cout << pokemon_2.get_nome() << " sofreu " << (int)pokemon_2.get_estatistica(0)/8 << " de dano pelo envenenamento!\n"; pokemon_2.set_vidaAtual(pokemon_2.get_vidaAtual() - pokemon_2.get_estatistica(0)/8); break; // Aplica o dano do envenenamento
        }

        if(pokemon_1.get_vidaAtual() <= 0 || pokemon_2.get_vidaAtual() <= 0) // Confere se algum Pokémon morreu
            break;

        turno++; // Aumenta o contador de turnos
    }

    if(pokemon_1.get_vidaAtual() > pokemon_2.get_vidaAtual()) // Verifica quem ganhou
        std::cout << "\nParabéns " << treinador1.get_nome() << ", você ganhou!\n";
    else
        std::cout << "\nParabéns " << treinador2.get_nome() << ", você ganhou!\n";

    delete[] tipos;
    delete[] pokemon;
    delete[] golpes;
    delete[] condicionais;
    delete[] modificaests;
    
    return 0;
}
