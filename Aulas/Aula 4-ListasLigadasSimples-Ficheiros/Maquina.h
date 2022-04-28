/*****************************************************************//**
 * \file   Maquina.h
 * \brief  
 * 
 * \author lufer
 * \date   April 2022
 *********************************************************************/
#include <stdbool.h>

#ifndef A
#define A 1

typedef struct Maquina {
	int num;
}Maquina, *PtrMaquina;

typedef struct ListaMaquinas {
	Maquina maquina;
	struct ListaMaquinas* prox; //ou apenas  PtrMaquina prox;
}ListaMaquinas;

#pragma region Assinatura_de_funções

//Cria nova mquina
Maquina* CriaMaquinaNova(int num);

/// Cria registo para inserir na linha de montagem
ListaMaquinas* CriaMaquinaLinha(Maquina* nova);

//Apresenta todas as máquinas
void MostraLinhaMontagem(ListaMaquinas* h);

//Insere máquina no início
ListaMaquinas* InsereNovaInicio(ListaMaquinas* head, Maquina* nova);

//Insere máquina no final
ListaMaquinas* InsereNovaFim(ListaMaquinas* head, Maquina* nova);

//Insere máquina de forma ordenada
ListaMaquinas* InserePorOrdem(ListaMaquinas* head, Maquina* nova);

/// Verifica se determinado número de máquina já existe
bool ExisteMaquina(int numMaquina, ListaMaquinas* head);

//Destroi lista
ListaMaquinas* DeleteAll(ListaMaquinas* h);

//Gerir Preservação de Dados - Ficheiros
//Guarda Dados
bool PreservaInformação(char fileName[], ListaMaquinas* h);
//Carrega Dados
ListaMaquinas* CarregaDados(char fileName[], ListaMaquinas* h);



#pragma endregion

#endif
