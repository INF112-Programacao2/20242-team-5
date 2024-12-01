#include "tipo.h"

int normal[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0, 1, 1, 0.5, 1}; // Não afeta: fantasma. Fraco contra: pedra e aço.
Tipo Normal("Normal", 0, normal);

int fogo[18] = {1, 0.5, 0.5, 2, 1, 2, 1, 1, 1, 1, 1, 2, 0.5, 1, 0.5, 1, 2, 1}; // Fraco contra: fogo, água, pedra, dragão. Superefetivo contra: grama, gelo, inseto e aço.
Tipo Fogo("Fogo", 1, fogo);

int agua[18] = {1, 2, 0.5, 0.5, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0.5, 1, 1, 1}; // Fraco contra: água, grama, dragão. Superefetivo contra: fogo, solo e pedra.
Tipo Agua("Água", 2, agua);

int grama[18] = {1, 0.5, 2, 0.5, 1, 1, 1, 0.5, 2, 0.5, 1, 0.5, 2, 1, 0.5, 1, 0.5, 1}; // Fraco contra: fogo, grama, veneno, voador, inseto, dragão e aço. Superefetivo contra: água, solo e pedra.
Tipo Grama("Grama", 3, grama);

int eletrico[18] = {1, 1, 2, 0.5, 0.5, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0.5, 1, 1, 1}; // Não afeta: solo. Fraco contra: grama, elétrico e dragão. Superefetivo contra: água e voador.
Tipo Eletrico("Elétrico", 4, eletrico);

int gelo[18] = {1, 0.5, 0.5, 2, 1, 0.5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 0.5, 1}; // Fraco contra: fogo, água, gelo e aço. Superefetivo contra: grama, solo, voador e dragão.
Tipo Gelo("Gelo", 5, gelo);

int lutador[18] = {2, 1, 1, 1, 1, 2, 1, 0.5, 1, 0.5, 0.5, 0.5, 2, 0, 1, 2, 2, 0.5}; // Não afeta: fantasma. Fraco contra: veneno, voador, psíquico, inseto, fada. Superefetivo contra: normal, gelo, pedra, escuridão e aço.
Tipo Lutador("Lutador", 6, lutador);

int veneno[18] = {1, 1, 1, 2, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1, 0, 2}; // Não afeta: aço. Fraco contra: veneno, solo, pedra e fantasma. Superefetivo contra: grama, fada.
Tipo Veneno("Veneno", 7, veneno);

int solo[18] = {1, 2, 1, 0.5, 2, 1, 1, 2, 1, 0, 1, 0.5, 2, 1, 1, 1, 2, 1}; // Não afeta: voador. Fraco contra: grama e inseto. Superefetivo contra: fogo, elétrico, veneno, pedra e aço.
Tipo Solo("Solo", 8, solo);

int voador[18] = {1, 1, 1, 2, 0.5, 1, 2, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 0.5, 1}; // Fraco contra: elétrico, pedra e aço. Superefetivo contra: grama, lutador e inseto.
Tipo Voador("Voador", 9, voador);

int psiquico[18] = {1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 0.5, 1, 1, 1, 1, 0, 0.5, 1}; // Não afeta: escuridão. Fraco contra: psíquico e aço. Superefetivo contra: lutador e veneno.
Tipo Psíquico("Psíquico", 10, psiquico);

int inseto[18] = {1, 0.5, 1, 2, 1, 1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 0.5, 1, 2, 0.5, 0.5}; // Fraco contra: fogo, lutador, veneno, voador, fantasma, aço e fada. Superefetivo contra: grama, psiquico, escuridão.
Tipo Inseto("Inseto", 11, inseto);

int pedra[18] = {1, 2, 1, 1, 1, 2, 0.5, 1, 0.5, 2, 1, 2, 1, 1, 1, 1, 0.5, 1}; // Fraco contra: lutador, solo e aço. Superefetivo contra: fogo, gelo, voador e inseto.
Tipo Pedra("Pedra", 12, pedra);

int fantasma[18] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 1, 1}; // Não afeta: normal. Fraco contra: escuridão. Superefetivo contra: psíquico e fantasma.
Tipo Fantasma("Fantasma", 13, fantasma);

int dragao[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0.5, 0}; // Não afeta: fada. Fraco contra: aço. Superefetivo contra: dragão.
Tipo Dragao("Dragão", 14, dragao);

int escuridao[18] = {1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 2, 1, 1, 2, 1, 0.5, 1, 0.5}; // Fraco contra: lutador, escuridão e fada. Superefetiva contra: psíquico e fantasma.
Tipo Escuridao("Escuridão", 15, escuridao);

int aco[18] = {1, 0.5, 0.5, 1, 0.5, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0.5, 2}; // Fraco contra: fogo, água, elétrica e aço. Superefetiva contra: gelo, pedra e fada.
Tipo Aco("Aço", 16, aco);

int fada[18] = {1, 0.5, 1, 1, 1, 1, 2, 0.5, 1, 1, 1, 1, 1, 1, 2, 2, 0.5, 1}; // Fraco contra: fogo, veneno e aço. Superefetivo contra: lutador, dragão e escuridão.
Tipo Fada("Fada", 17, fada);