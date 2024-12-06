#include "Golpe.hpp"
#include "Condicional.hpp"
#include "ModificaEst.hpp"
#include "tipos.cpp"

Golpe normalFisico("Força", 80, 100, Normal, 0); // Golpe simples chamado Strength, com 80 de poder base, 100% de precisão, tipo normal e físico
Golpe normalEspecial("Super Voz", 90, 100, Normal, 1); // Golpe simples chamado Hyper Voice, com 90 de poder base, 100% de precisão, tipo normal e especial
ModificaEst normalStatus("Dança das Espadas", 0, 100, Normal, 1, 2, 0, 0, 0, 0, 100, 1); // Golpe que modifica estatística chamado Swords Dance, com 0 de poder base, 100% de precisão, tipo normal, especial, que adiciona 2 estágios ao ataque e zero às outras estatísticas, com 100% de chance de ativação e que afeta o próprio usuário

Condicional fogoFisico("Bola de Fogo", 120, 90, Fogo, 0, 1, 10); // Golpe que aplica uma condição chamado Pyro Ball, com 120 de poder base, 90% de precisão, tipo fogo, físico, que aplica queimadura com 10% de chance de ativação
ModificaEst fogoEspecial("Superaquecer", 130, 90, Fogo, 1, 0, 0, -2, 0, 0, 100, 1); // Golpe que modifica estatística chamado Overheat, com 130 de poder base, 90% de precisão, tipo fogo, especial, que subtrai dois estágios ao ataque especial e zero às outras estatísticas, com 100% de chance de ativação e que afeta o próprio usuário
Condicional fogoStatus("Fogo-Fátuo", 0, 85, Fogo, 1, 1, 100); // Golpe que aplica uma condição chamado Will-O-Wisp, com 0 de poder base, 85% de precisão, tipo fogo, especial, que aplica queimadura com 100% de chance de ativação

ModificaEst aguaFisico("Liquidação", 85, 100, Agua, 0, 0, -1, 0, 0, 0, 20, 1);
Golpe aguaEspecial("Prensa Hidráulica", 110, 80, Agua, 1);
ModificaEst aguaStatus("Recolher", 0, 100, Agua, 1, 0, 1, 0, 1, 0, 100, 1);

Golpe gramaFisico("Chicote", 120, 85, Grama, 0);