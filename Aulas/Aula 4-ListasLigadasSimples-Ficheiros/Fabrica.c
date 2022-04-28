/*****************************************************************//**
 * \file   Fabrica.c
 * \brief	Gestão de Linha de Montagem
 *			Definição de Funções
 *			Gestão de Ficheiros
 * 
 * \author lufer
 * \date   April 2022
 *********************************************************************/
#include "Maquina.h"
#include <stdio.h>
#include <stdbool.h>

#pragma warning (disable: 4996)

/// <summary>
/// Aloca espaço em memória para uma nova máquina
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
Maquina* CriaMaquinaNova(int num) {
	Maquina* aux;
	aux = (Maquina*)calloc(sizeof(Maquina));
	if(aux!=NULL)
		aux->num = num;
	return aux;
}

/**
 * @brief Cria registo para inserir na linha de montagem
 * 
 * @param nova
 * @return 
 */
ListaMaquinas* CriaMaquinaLinha(Maquina* nova) {
	ListaMaquinas* aux = (ListaMaquinas*)calloc(sizeof(ListaMaquinas));
	if (aux != NULL) {
		aux->maquina = *nova;
		aux->prox = NULL;
	}
	return aux;
}

/// <summary>
/// Insere uma máquina nova no início da linha de montagem
/// O início da lista resulta alterado
/// Parte-se do principio que a máquina ainda não existe
/// Implementa uma Stack
/// </summary>
/// <param name="h">Inicio da Lista</param>
/// <param name="n">Maquina nova</param>
/// <returns>Inicio da Lista</returns>
ListaMaquinas* InsereNovaInicio(ListaMaquinas* head, Maquina* nova) {
	
	//Se a lista é vazia, cria-se a lista com esta nova maquina
	if (head == NULL) {
		ListaMaquinas* aux = CriaMaquinaLinha(nova);
		head = aux;
	}
	//h!=NULL --- significa que a linha tem mais máquinas...vai inserir no inicio da lista
	else
	{
		//Se já existe a máquina nada é alterado
		if (ExisteMaquina(nova->num, head) == false)	
		{
			ListaMaquinas *aux = CriaMaquinaLinha(nova);
			aux->prox = nova;
			head->prox=nova;
		}
	}
	return head;
}

/// <summary>
/// Insere uma máquina nova no fim da linha de montagem
/// O início da lista pode resultar alterado
/// Parte-se do principio que a máquina ainda não existe
/// Implementa uma Queue ou Fila 
/// </summary>
/// <param name="head">Inicio da Lista</param>
/// <param name="nova">Nova Maquina a inserir</param>
/// <returns>Novo Inicio da Lista</returns>
ListaMaquinas* InsereNovaFim(ListaMaquinas* head, Maquina* nova) {
	//Se a lista é vazia, cria-se a lista com esta nova maquina
	if (head == NULL) {
		ListaMaquinas* aux = CriaMaquinaLinha(nova);
		head = aux;
	}
	else
	{
		//Se já existe a máquina, nada é alterado
		if (ExisteMaquina(nova->num, head) == false)
		 {
			ListaMaquinas* aux = head;
			//coloca-se no fim  da lista de máquinas
			while (aux->prox != NULL)
				aux = aux->prox;
			//insere no fim
			ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
			aux->prox = auxNova;
		}
	}
	return head;
}

/**
 * @brief	Insere uma nova máquina ordenado pelo número de máquina
 *			O início da lista pode resultar alterado
 *			Parte-se do principio que a máquina ainda não existe.
 * 
 * @param head
 * @param nova
 * @return 
 */
ListaMaquinas* InserePorOrdem(ListaMaquinas* head, Maquina* nova){
	if (head == NULL) {
		ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
		head = auxNova;
	}
	else
	{
		//Se já existe a máquina, nada é alterado
		if (ExisteMaquina(nova->num, head) == false)
		{
			//cria novo registo de máquina
			ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
			//Auxiliares para encontar a posição onde inserir
			ListaMaquinas* aux1 = head;
			ListaMaquinas* aux2 = head;
			while (aux1 != NULL && aux1->maquina.num < nova->num) {
				aux2 = aux1;
				aux1 = aux1->prox;
			}
			//Se porventura tiver que ficar no início, o head é alterado
			if (aux1 == head) {
				auxNova->prox = head;
				head = auxNova;
			}
			else
			{
				if (aux1 == NULL) {			//Insere no fim
					aux2->prox = auxNova;
				}
				//se não inserir entre aux 2 e aux1
				else {
					auxNova->prox = aux1;
					aux2->prox = auxNova;
				}
			}
		}
	}
	return head;
}

/**
 * @brief Mostrar todas as maquinas.
 * 
 * @param h
 */
void MostraLinhaMontagem(ListaMaquinas* h) {
	ListaMaquinas* aux = h;
	while (aux != NULL)
	{
		printf("Maquina: %d\n", aux->maquina.num);
		aux = aux->prox;
	}
}

/**
 * @brief Verifica se determinado número de máquina já existe.
 * 
 * @param numMaquina
 * @param head
 * @return 
 */
bool ExisteMaquina(int numMaquina, ListaMaquinas* head) {
	if (head == NULL) return false;
	ListaMaquinas* aux = head;
	while (aux != NULL && aux->maquina.num!= numMaquina) {
		aux = aux->prox;
	}
	//se (aux !==NULL)==true então é porque foi encontrada uma máquina com o número que se procura
	return (aux != NULL);		
}

/**
 * @brief .
 * 
 * @param fileName
 * @param h
 * @return 
 */
bool PreservaInformação(char fileName[], ListaMaquinas* h) {
	FILE* fp;
	if (h == NULL) 
		return false;
	if ((fp = fopen(fileName, "wb")) == NULL)		//w-write
	{
		return false;
	}

	ListaMaquinas* current = h;
	while (current != NULL) {
		//fseek(fp, 0, SEEK_END);
		fwrite(&current->maquina, sizeof(Maquina), 1, fp);
		current = current->prox;
	}

	fclose(fp);
	return true;
}

/**
 * @brief Carrega informação de Ficheiro
 * 
 * @param fileName
 * @param h
 * @return 
 */
ListaMaquinas* CarregaDados(char fileName[], ListaMaquinas* h) {
	FILE* fp;
	fp = fopen(fileName, "rb");		//r - read
	if (fp == NULL) 
		return false;

	//limpar lista
	//if(h!=NULL) DeleteAll(h);
	//h = NULL;

	//ler e construir lista
	Maquina* aux;
	aux = (Maquina*)calloc(sizeof(Maquina));
	while (fread(aux, sizeof(Maquina), 1, fp) != 0) {
		h = InserePorOrdem(h,aux);
		aux = (Maquina*)calloc(sizeof(Maquina));
	}
	fclose(fp);
	fp = NULL;
	return h;
}

/**
 * @brief Destroi uma lista
 * 
 * @param h
 * @return 
 */
ListaMaquinas* DeleteAll(ListaMaquinas* h) {
	ListaMaquinas* aux;

	aux = h;
	while (aux != NULL) {
		h = aux->prox;
		free(aux);
		aux = h;
	}
	return h;
}
