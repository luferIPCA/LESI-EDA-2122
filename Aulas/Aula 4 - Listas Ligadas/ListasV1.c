/**
* author: lufer
* email:lufer@ipca.pt
* date: 2022
* Desc: Lista Ligadas Simples
*/

#include <stdio.h>
#include "Dados.h"


/*
Cria novo Jogo. Aloca memória necessária
*/
Jogo* criaJogo(int cod, char* nome, int tipo)
{
	Jogo* newJogo = (Jogo*)malloc(sizeof(Jogo));
	if (newJogo == NULL) return NULL;	//pode não haver memória!!!
	newJogo->cod = cod;
	strcpy(newJogo->nome, nome);
	newJogo->tipo = tipo;
	newJogo->next = NULL;
	return newJogo;
}

/*
Insere um novo jogo no início da estrutura
*/
Jogo* InsereJogoInicio(Jogo* h, Jogo* novo) {
	//Verificar se o novo jogo já existe!!!
	if (ExisteJogoII(h, novo->cod)) return h;	//se existir não insere!

	if (h == NULL)		//Lista está vazia
	{
		h = novo;
	}
	else
	{
		novo->next = h;	//aponta para onde "h" está a apontar
		h = novo;
	}
	return h;
}


/*
Insere jogo no final da lista
*/
Jogo* InsereJogoFim(Jogo* h, Jogo* novo) {
	//Verificar se o novo jogo já existe!!!
	if (ExisteJogoII(h, novo->cod)) return h;	//se existir não insere!

	if (h == NULL) {		//lista vazia
		h = novo;
	}
	else
	{
		//Posicionar-se no fim da lista
		Jogo* aux = h;
		while (aux->next != NULL) {
			aux = aux->next;
		}
		//insere no fim da lista
		aux->next = novo;
	}
	return h;
}


/*
Insere Jogo ordenado pelo código
*/
Jogo* InsereJogoOrdenado(Jogo* h, Jogo* novo) {
	if (ExisteJogoII(h, novo->cod)) return h;

	if (h == NULL) {
		h = novo;
	}
	else
	{
		Jogo* aux = h;
		Jogo* auxAnt = NULL;
		while (aux && aux->cod < novo->cod) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {
			novo->next = h;
			h = novo;
		}
		else
		{
			auxAnt->next = novo;
			novo->next = aux;
		}
	}
	return h;
}

/*
Mostra todos os jogos existentes na estrutura
*/
void MostraLista(Jogo* h) {
	Jogo* aux = h;
	while (aux) {		//(aux!=NULL)
		MostraJogo(aux);
		aux = aux->next;
	}
}

/*
//Mostra Nodo
*/
void MostraJogo(Jogo* nodo) {
	if (nodo != NULL)
	{
		printf("\nFicha de Jogo:\nJogo= %s\n", nodo->nome);
		printf("Codigo= %d\n", nodo->cod);
		printf("Tipo= %c\n", nodo->tipo);
	}
}

/**
*Verifica se jogo existe. Se existir devolve Bool!
*/
bool ExisteJogoII(Jogo *h, int cod) {
	if (h == NULL) return false;
	Jogo* aux = h;
	while (aux != NULL) {
		if (aux->cod == cod)
			return true;
		aux = aux->next;
	}
	return false;
}

//
///*
//Remove jogo
//*/
//JogoListaPtr RemoveJogo(JogoListaPtr h, int cod) {
//
//	if (h == NULL) return NULL;			//Lista vazia
//	if (!ExisteJogo(h, cod)) return h;	//se não existe
//
//	JogoListaPtr aux = h;
//	JogoListaPtr auxAnt = NULL;
//
//	//localizar registo a eliminar
//	while (aux && aux->jogo.cod != cod) {
//		auxAnt = aux;
//		aux = aux->next;
//	}
//	if (auxAnt == NULL) {	//Eliminar à cabeça
//		h = h->next;
//		free(aux);
//	}
//	else					//Elimiar no meio
//	{
//		auxAnt->next = aux->next;
//		free(aux);
//	}
//	return h;
//}
//
///*
//Verifica se jogo existe. Se existir devolve jogo!
//*/
//JogoLista* ProcuraJogo(JogoLista* h, int cod) {
//	if (h == NULL) return NULL;
//	else
//	{
//		JogoLista* aux = h;
//		while (aux != NULL) {
//			if (aux->jogo.cod == cod)
//				return (aux);
//			aux = aux->next;
//		}
//		return NULL;
//	}
//}
//
///*

//
///*
//Contar jogos de determinado tipo, numa lista ligada
//*/
//int ContaJogos(JogoLista* h, char tipo) {
//	int c = 0;
//	JogoListaPtr aux = h;	//inicio da lista
//	while (aux != NULL) {
//		if (aux->jogo.tipo == tipo) {
//			c++;
//		}
//		aux = aux->next;
//	}
//	return c;
//}
//
///*
//Conta jogos de determinado tipo num array de jogos
//*/
//int ContaJogosArray(Jogo v[], int size, char tipo) {
//	int c = 0;	//contador
//	//h1
//	for (int i = 0; i < size; i++) {
//		if (v[i].tipo == tipo) {
//			c++;
//		}
//	}
//	//h2
//	/*int i = 0;
//	while (i < size) {
//		if (v[i].tipo == tipo) {
//			c++;
//		}
//		i++;
//	}*/
//	return c;
//}
//
///*
//Constroi uma lista a partir de um array de inteiros
//Não recursivo
//*/
//JogoLista* ConsList(Jogo* v, int size)
//{
//	JogoListaPtr h = NULL, aux;
//	if (size <= 0) return NULL;
//
//	for (int i = 0; i < size; i++)
//	{
//		//h = Append(v[i], h);
//		h = InsereJogoFim(h, &v[i]);
//	}
//	return h;
//}
//
///*
//Constroi uma lista a partir de um array de inteiros
//Recursivo
//Versão 1
//*/
//JogoLista* ConsListRec(Jogo* v, int size)
//{
//	JogoListaPtr h = NULL, aux;
//
//	if (size <= 0) return NULL;
//
//	h = (JogoListaPtr)malloc(sizeof(JogoLista));
//	h->jogo = v[0];
//	h->next = ConsListRec(v + 1, size - 1);;
//
//	return h;
//}
//
///*
//Constroi uma lista a partir de um array de inteiros
//Recursivo
//Versão 2
//*/
//JogoLista* ConsListRecII(Jogo v[], int i, int size)
//{
//	JogoListaPtr h = NULL, aux;
//
//	if (size <= 0) return NULL;
//
//	h = (JogoListaPtr)malloc(sizeof(JogoLista));
//	h->jogo = v[i];
//	h->next = ConsListRecII(v, i + 1, size - 1);;
//
//	return h;
//}
//
// ========================= Ficheiros ============================

#pragma region FICHEIROS

//Ver : https://www.geeksforgeeks.org/readwrite-structure-file-c/

/*
Preservar dados em ficheiro
*/
bool gravarJogoBinario(char* nomeFicheiro, Jogo* h) {
	FILE* fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	Jogo* aux = h;
	while (aux) {		//while(aux!=NULL)
		fwrite(aux, sizeof(Jogo), 1, fp);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}

/*
Lê informação de ficheiro
*/
Jogo* lerJogosBinario(char* nomeFicheiro) {
	FILE* fp;
	Jogo* h = NULL;
	Jogo* aux;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	//lê n registos no ficheiro
	aux = (Jogo*)malloc(sizeof(Jogo));
	while (fread(aux, sizeof(Jogo), 1, fp)) {
		//printf("Jogo=%s\n", aux->nome);
		h = InsereJogoOrdenado(h, aux);
		aux = (Jogo*)malloc(sizeof(Jogo));
	}
	fclose(fp);
	return h;
}
#pragma endregion

