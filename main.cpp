#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Pokemon.hpp"
#include "Golpe.hpp"
#include "Tipo.hpp"

Pokemon* lerPokemonDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return nullptr;
    }

    std::string linha;
    int id = 0;
    std::string nome;
    int vida = 0, ataque = 0, defesa = 0, ataqueEspecial = 0, defesaEspecial = 0, velocidade = 0;
    int tipo1Num = 0, tipo2Num = 0;
    
    // Golpes do Pokémon como variáveis separadas
    Golpe _golpe1, _golpe2, _golpe3, _golpe4;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string token;

        if (linha.find("id:") != std::string::npos) {
            iss >> token >> id;
        }
        else if (linha.find("nome:") != std::string::npos) {
            std::getline(iss >> token, nome);
        }
        else if (linha.find("estatísticaS:") != std::string::npos) {
            iss >> token >> vida >> ataque >> defesa >> ataqueEspecial >> defesaEspecial >> velocidade;
        }
        else if (linha.find("tipos:") != std::string::npos) {
            iss >> token >> tipo1Num >> tipo2Num;
        }
        else if (linha.find("golpe:") != std::string::npos) {
            std::string golpeNome;
            int golpePoderBase, golpePrecisao, golpeTipoNum, golpeEspecial;

            // Substituir underscores por espaços no nome do golpe
            std::string fullLine;
            std::getline(iss >> token, fullLine);
            std::replace(fullLine.begin(), fullLine.end(), '_', ' ');

            // A próxima linha contém os detalhes do golpe
            std::string detalhesLinha;
            std::getline(arquivo, detalhesLinha);
            std::istringstream detalhesStream(detalhesLinha);
            
            detalhesStream >> golpePoderBase >> golpePrecisao >> golpeTipoNum >> golpeEspecial;

            Tipo golpeTipo;
            golpeTipo.set_numRep(golpeTipoNum);

            // Armazenando os golpes nas variáveis individuais
            if (_golpe1.get_nome().empty()) {
                _golpe1 = Golpe(fullLine, golpePoderBase, golpePrecisao, golpeTipo, golpeEspecial);
            } else if (_golpe2.get_nome().empty()) {
                _golpe2 = Golpe(fullLine, golpePoderBase, golpePrecisao, golpeTipo, golpeEspecial);
            } else if (_golpe3.get_nome().empty()) {
                _golpe3 = Golpe(fullLine, golpePoderBase, golpePrecisao, golpeTipo, golpeEspecial);
            } else if (_golpe4.get_nome().empty()) {
                _golpe4 = Golpe(fullLine, golpePoderBase, golpePrecisao, golpeTipo, golpeEspecial);
            }

            if (_golpe4.get_nome() != "") break;  // Se já tiver lido 4 golpes, podemos parar
        }
    }

    arquivo.close();

    Tipo tipo1, tipo2;
    tipo1.set_numRep(tipo1Num);
    tipo2.set_numRep(tipo2Num);

    return new Pokemon(id, nome, vida, ataque, defesa, ataqueEspecial, defesaEspecial, velocidade, 
                       tipo1, tipo2, 
                       _golpe1, _golpe2, _golpe3, _golpe4);
}

int main() {
    // Certifique-se de que o arquivo 'dados.txt' está no mesmo diretório
    Pokemon* pikachu = lerPokemonDeArquivo("dados.txt");

    if (pikachu) {
        std::cout << "Pokemon " << pikachu->get_nome() << " carregado com sucesso!" << std::endl;
        std::cout << "ID: " << pikachu->get_id() << std::endl;
        std::cout << "Vida: " << pikachu->get_estatistica(0) << std::endl;
        std::cout << "Ataque: " << pikachu->get_estatistica(1) << std::endl;
        std::cout << "Defesa: " << pikachu->get_estatistica(2) << std::endl;
        std::cout << "Ataque Especial: " << pikachu->get_estatistica(3) << std::endl;
        std::cout << "Defesa Especial: " << pikachu->get_estatistica(4) << std::endl;
        std::cout << "Velocidade: " << pikachu->get_estatistica(5) << std::endl;

        std::cout << pikachu->get_golpe1().get_nome() << std::endl;
        std::cout << pikachu->get_golpe1().get_poderBase() << std::endl;
    }

    delete pikachu;
    return 0;
}
