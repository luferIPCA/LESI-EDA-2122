/**
* lufer
* Structs com Apontadores
* Listas Ligadas Simples
*/

#ifndef DADOS
#define DADOS

#include <stdbool.h>
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#define N 20

#pragma region VERSAO1

typedef struct Jogo {
	int cod;
	char nome[N];
	char tipo;
	struct Jogo* next;		//aponta para próximo jogo!!!
}Jogo, *JogoPtr;

extern Jogo* headLista;

bool ExisteJogoII(Jogo* h, int cod);
Jogo* criaJogo(int cod, char* nome, int tipo);
Jogo* InsereJogoInicio(Jogo* h, Jogo* novo);
Jogo* InsereJogoOrdenado(Jogo* h, Jogo* novo);
Jogo* InsereJogoFim(Jogo* h, Jogo* novo);
bool gravarJogoBinario(char* nomeFicheiro, Jogo* h);
Jogo* lerJogosBinario(char* nomeFicheiro);

void MostraLista(Jogo* h);
//apresenta ficha de jogo
void MostraJogo(Jogo* nodo);

#pragma endregion


#endif