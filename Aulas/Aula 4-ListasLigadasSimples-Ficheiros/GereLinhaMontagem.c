/*****************************************************************//**
 * \file   Fabrica.c
 * \brief	Gestão de Linha de Montagem
 *			Gestão de Ficheiros
 *
 * \author lufer
 * \date   April 2022
 *********************************************************************/
#include "Maquina.h"
#include <stdio.h>

int main() {

#pragma region Basico

	Maquina m1;
	m1.num = 1;

	Maquina m2;
	m2.num = 2;

	Maquina* pt;
	pt = &m1;

	//(*pt).num			//apontado por pt campo "num"
	//ou
	//pt->num
	pt->num = 12;
	pt->num++;

	ListaMaquinas* l1 = (ListaMaquinas*)calloc(sizeof(ListaMaquinas));
	//l1 contém m1
	l1->maquina = m1;
	//l1 a apontar para m2
	l1->prox = &m2;

	printf("Maquina M1: %d\n", l1->maquina.num);		//escreve valor "num" de m1
	printf("Maquina M2: %d\n", l1->prox->maquina.num);	//escreve valor "num" de m1

	//m2 a apontar para m1
	ListaMaquinas* l2 = (ListaMaquinas*)calloc(sizeof(ListaMaquinas));
	l2->maquina = m2;
	l2->prox = &m1;
	printf("Maquina M1: %d\n", l2->prox->maquina.num);	//escreve valor "num" de m1 == m2.prox->num

#pragma endregion

#pragma region GereLinhaMontagem


	ListaMaquinas* head = NULL;		//marca o ínicio da lista; No inicio a lista está vazia
	
	head = CarregaDados("Fabrica1", head);		//Carrega dados do ficheiro
	
	if (head == NULL) {
		//a)
		Maquina* nova = CriaMaquinaNova(12);
		//b)
		//i) Insere o 1º elemento da lista
		/*if (head == NULL) {
			head = nova;
		}*/

		//nova maquina
		nova = CriaMaquinaNova(120);

		//ii) Insere sempre no inicio da lista
		/*if(head != NULL) {
			nova->prox = head;
			head = nova;
		}*/

		head = InsereNovaInicio(head, nova);

		//iii)Insere sempre no final da lista
		//- Procurar o fim da lista
		//Maquina* aux = head;
		//while (aux->prox != NULL)
		//	aux = aux->prox;
		////insere no fim
		//aux->prox = nova;


		head = NULL;
		nova = CriaMaquinaNova(13);
		head = InsereNovaFim(head, nova);
		nova = CriaMaquinaNova(14);
		head = InsereNovaFim(head, nova);
		nova = CriaMaquinaNova(7);
		head = InsereNovaFim(head, nova);
		MostraLinhaMontagem(head);


		head = NULL;
		nova = CriaMaquinaNova(13);
		head = InserePorOrdem(head, nova);
		nova = CriaMaquinaNova(14);
		head = InserePorOrdem(head, nova);
		nova = CriaMaquinaNova(7);
		head = InserePorOrdem(head, nova);
		MostraLinhaMontagem(head);

	}
	MostraLinhaMontagem(head);

	//head = DeleteAll(head);
	//MostraLinhaMontagem(head);

	bool resultado = PreservaInformação("Fabrica1", head);	//Guarda dados no ficheiro

#pragma endregion
}