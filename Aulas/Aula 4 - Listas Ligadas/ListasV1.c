/**
*  @file ListasV2.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 *	Metodos para manipular uma Lista Ligada Simples

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 * @bug No known bugs.
*/

#include <stdio.h>
#include "Dados.h"


/**
*	@brief Cria novo Jogo.
*
*	Aloca memória necessária para armazenar um jogo em memória
*
*	@param nome Nome do Jogo
*	@param cod	Código do Jogo
*	@param tipo	Tipo do Jogo
*
*/
Jogo* criaJogo(int cod, char* nome, int tipo)
{
	Jogo* newJogo = (Jogo*)malloc(sizeof(Jogo));
	//Jogo* newJogo = (Jogo*)calloc(sizeof(Jogo));	//analisar a diferença!
	if (newJogo == NULL) return NULL;	//pode não haver memória!!!
	newJogo->cod = cod;
	strcpy(newJogo->nome, nome);
	newJogo->tipo = tipo;
	newJogo->next = NULL;
	return newJogo;
}

/**
* @brief Insere um novo jogo no início da estrutura
* @param [in] h		Inicio da Lista
* @param [in] novo	Novo jogo a inserir
* @return	Inicio da Lista
*/
Jogo* InsereJogoInicio(Jogo* h, Jogo* novo) {
	
	if (novo == NULL) return h;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

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

void InsereJogoInicioII(Jogo** h, Jogo* novo) {

	if (novo == NULL) return h;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(*h, novo->cod)) return h;	//se existir não insere!

	if (*h == NULL)		//Lista está vazia
	{
		*h = novo;
	}
	else
	{
		novo->next = *h;	//aponta para onde "h" está a apontar
		*h = novo;
	}
	return *h;
}

void InsereJogoInicioIII(Jogo* h, Jogo* novo) {

	if (novo == NULL) 
		h=NULL;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return;	//se existir não insere!

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



/**
* @brief Insere jogo no final da lista
* @param [in] h		Inicio da Lista
* @param [in] novo	Novo jogo a inserir
* @return	Inicio da Lista
*/
Jogo* InsereJogoFim(Jogo* h, Jogo* novo) {
	//Verificar se o novo jogo já existe!!!
	if (ExisteJogo(h, novo->cod)) return h;	//se existir não insere!

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

/**
* @brief Insere Jogo ordenado pelo código
* @param [in] h		Inicio da Lista
* @param [in] novo	Novo jogo a inserir
* @return	Inicio da Lista
*/
Jogo* InsereJogoOrdenado(Jogo* h, Jogo* novo) {
	if (ExisteJogo(h, novo->cod)) return h;

	if (h == NULL) {
		h = novo;		//Insere no início
	}
	else
	{
		Jogo* aux = h;
		Jogo* auxAnt = NULL;
		while (aux && aux->cod < novo->cod) {
			auxAnt = aux;
			aux = aux->next;
		}
		if (auxAnt == NULL) {	//Insere no meio
			novo->next = h;
			h = novo;
		}
		else
		{
			auxAnt->next = novo;	//Insere no fim
			novo->next = aux;
		}
	}
	return h;
}


/**
* @brief Verifica se jogo existe. Se existir devolve Bool!
* @param [in] h		Inicio da Lista
* @param [in] cod	código do jogo a procurar
* @return	True/False
*/
bool ExisteJogo(Jogo *h, int cod) {
	if (h == NULL) return false;
	Jogo* aux = h;
	while (aux != NULL) {
		if (aux->cod == cod)
			return true;
		aux = aux->next;
	}
	return false;
}

/**
* @brief Verifica se jogo existe. Se existir devolve Bool!
*	Implementação Recursiva
* @param [in] h		Inicio da Lista
* @param [in] cod	código do jogo a procurar
* @return	True/False
*/
bool ExisteJogoRecursivo(Jogo* h, int cod) {
	if (h == NULL) return false;
	if (h->cod == cod) return true;
	return (ExisteJogoRecursivo(h->next,cod));
}

/**
* @brief Verifica se jogo existe. Se existir devolve endereço jogo!
* @param [in] h		Inicio da Lista
* @param [in] cod	código do jogo a procurar
* @return	Apontador para jogo encontrado
*/
Jogo* ProcuraJogoPtr(Jogo* h, int cod) {
	if (h == NULL) return NULL;		//lista vazia
	else
	{
		Jogo* aux = h;
		while (aux != NULL) {
			if (aux->cod == cod) {
				return (aux);		//encontrei
			}
			aux = aux->next;
		}
		return NULL;
	}
}


/**
* @brief Verifica se jogo existe. Se existir devolve cópia do jogo!
* @param [in] h		Inicio da Lista
* @param [in] cod	código do jogo a procurar
* @return	Apontador para cópia do jogo encontrado
*/
Jogo* ProcuraJogo(Jogo* h, int cod) {
	if (h == NULL) return NULL;
	else
	{
		Jogo* aux = h;
		while (aux != NULL) {
			if (aux->cod == cod) {
				//cria copia do jogo encontrado
				Jogo* auxJogo = criaJogo(aux->cod, aux->nome,aux->tipo);
				return (auxJogo);
			}
			aux = aux->next;
		}
		return NULL;
	}
}


/**
* @brief Altera tipo de jogo
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	cod	Codigo do jogo a alterar
* @param [in]	novoTipo	novo tipo do jogo
* @return	Apontador para Lista
*/
Jogo* AlteraJogo(Jogo* h, int cod, char novoTipo) {
	Jogo* aux = ProcuraJogoPtr(h, cod);
	if (aux != NULL)		//se encontrou o jogo
	{
		aux->tipo = novoTipo;
	}
	return h;
}

/**
* @brief Altera um jogo: versão II
* @param [in]	h	Endereço do Apontador para inicio da Lista
* @param [in]	cod	Codigo do jogo a alterar
* @param [in]	novoTipo	novo tipo do jogo
* @return	Apontador para Lista
*/
void AlteraJogoPtr(Jogo** h, int cod, char tipo) {
	if (*h != NULL) {
		Jogo* aux = ProcuraJogoPtr(*h, cod);
		if (aux != NULL)		//se encontrou o jogo
		{
			aux->tipo = tipo;
		}
	}
}

/**
* @brief Remove jogo. Còdigo indexado pelo seu código (cod)
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	cod	Codigo do jogo a alterar
* @return	Apontador para Lista
*/
Jogo* RemoveJogo(Jogo *h, int cod) {
	if (h == NULL) return NULL;			//Lista vazia
	//if (!ExisteJogo(h, cod)) return h;	//se não existe

	if (h->cod == cod) {		//remove no inicio da lista
		Jogo* aux = h;
		h = h->next;
		free(aux);
	}
	else
	{
		Jogo *aux = h;
		Jogo *auxAnt = aux;
		while (aux && aux->cod != cod) {	//procura para revover
			auxAnt = aux;
			aux = aux->next;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->next = aux->next;
			free(aux);
		}
	}
	return h;
}

/**
* @brief Remove jogo de forma Recursiva. Còdigo indexado pelo seu código (cod)
* @param [in]	h	Apontador para inicio da Lista
* @param [in]	cod	Codigo do jogo a alterar
* @return	Apontador para Lista
*/
Jogo* RemoveJogoRecursivo(Jogo *head, int cod) {
	Jogo* aux;

	if (head == NULL)
		return NULL;

	if (head->cod==cod) {
		aux = head;
		head=head->next;
		free(aux);
	}
	else {
		head->next = RemoveJogoRecursivo(head->next, cod);
	}
	return head;
}

/**
* @brief Ordena Lista
* @param [in]	h	Apontador para inicio da Lista
* @return	Apontador para Lista ordenada
*/
Jogo* OrdenaLista(Jogo* h) {
	if (h == NULL) return NULL;
	Jogo* listaOrdenada=NULL;
	Jogo* aux=h;
	Jogo* novo;
	while (aux) {
		novo = criaJogo(aux->cod, aux->nome, aux->tipo);
		listaOrdenada = InsereJogoOrdenado(listaOrdenada, novo);
		aux = aux->next;
	}
	return listaOrdenada;
}


/**
* @brief Destroi todos os nodos da lista
* @param [in]	h	Apontador para inicio da Lista
*/

void DestroiLista(Jogo** h) {
	if (h != NULL) {
		Jogo* aux;
		while (*h) {
			aux = *h;
			*h = (*h)->next;
			free(aux);
		}
	}
}

/**
* @brief Contar jogos de determinado tipo
*/
int ContaJogos(Jogo* h, char tipo) {
	int c = 0;
	Jogo* aux = h;	//inicio da lista
	while (aux != NULL) {
		if (aux->tipo == tipo) {
			c++;
		}
		aux = aux->next;
	}
	return c;
}


void PercorreLista(Jogo* h, void(*f)(Jogo* h)) {
	f(h);
}

#pragma region FICHEIROS

// ========================= Ficheiros ============================
//Ver : https://www.geeksforgeeks.org/readwrite-structure-file-c/

/**
* @brief Preservar dados em ficheiro
* Grava todos os nodos da Lista em Ficheiro
*/
bool gravarJogoBinario(char* nomeFicheiro, Jogo* h) {
	FILE* fp;

	if (h == NULL) return false;
	if ((fp = fopen(nomeFicheiro, "wb")) == NULL) return false;
	//grava n registos no ficheiro
	Jogo* aux = h;
	JogoFile auxJogo;	//para gravar em ficheiro!
	while (aux) {		//while(aux!=NULL)
		//Colocar no registo de ficheiro a inf que está no registo de memória
		auxJogo.cod = aux->cod;
		strcpy(auxJogo.nome, aux->nome);
		auxJogo.tipo = aux->tipo;
		fwrite(&auxJogo, sizeof(JogoFile), 1, fp);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}

/**
* @brief Lê informação de ficheiro
*/
Jogo* lerJogosBinario(char* nomeFicheiro) {
	FILE* fp;
	Jogo* h = NULL;
	Jogo* aux;

	if ((fp = fopen(nomeFicheiro, "rb")) == NULL) return NULL;
	//lê n registos no ficheiro
	JogoFile auxJogo;
	while (fread(&auxJogo, sizeof(JogoFile), 1, fp)){
		//printf("Jogo=%s\n", auxJogo.nome);
		aux = criaJogo(auxJogo.cod, auxJogo.nome, auxJogo.tipo);
		h = InsereJogoOrdenado(h, aux);
	}
	fclose(fp);
	return h;
}
#pragma endregion

#pragma region OUTROS

/*----------------------------------------------------
*	Outros Métodos com Listas
 -----------------------------------------------------*/

/**
*	@brief Constroi uma lista a partir de um array de inteiros
*	Não recursivo
*/
Jogo* ConsList(Jogo* v, int size)
{
	Jogo *h = NULL, aux;
	if (size <= 0) return NULL;

	for (int i = 0; i < size; i++)
	{
		//h = Append(v[i], h);
		h = InsereJogoFim(h, &v[i]);
	}
	return h;
}

/**
* @brief  Constroi uma lista a partir de um array de inteiros
* Recursivo
* Versão 1
*/
Jogo* ConsListRec(Jogo* v, int size)
{
	Jogo* h = NULL, aux;

	if (size <= 0) return NULL;

	h = (Jogo*)malloc(sizeof(Jogo));
	h->cod = v[0].cod;
	//copiar o resto
	h->next = ConsListRec(v + 1, size - 1);;

	return h;
}

/**
*	@brief Constroi uma lista a partir de um array de inteiros
*	Recursivo
*	Versão 2
*/
Jogo* ConsListRecII(Jogo v[], int i, int size)
{
	Jogo* h = NULL, aux;

	if (size <= 0) return NULL;

	h = (Jogo*)malloc(sizeof(Jogo));
	h->cod= v[i].cod;
	//copiar o resto
	h->next = ConsListRecII(v, i + 1, size - 1);;

	return h;
}


/* -----------------------------------------------------
*	Métodos para mostrar no ecrã
   -----------------------------------------------------*/

   /**
   *	@brief Mostra todos os jogos existentes na estrutura
   */
void MostraLista(Jogo* h) {
	Jogo* aux = h;
	while (aux) {		//mesmo que while (aux!=NULL)
		MostraJogo(aux);
		aux = aux->next;
	}
}


/**
*	@brief Mostra dados de um nodo
*/
void MostraJogo(Jogo* nodo) {
	if (nodo != NULL)
	{
		printf("\nFicha de Jogo:\nJogo= %s\n", nodo->nome);
		printf("Codigo= %d\n", nodo->cod);
		printf("Tipo= %c\n", nodo->tipo);
	}
}


/*----------------------------------------------------
* Manipular Arrays - Auxiliares
* ----------------------------------------------------*/

/**
*	@brief Conta jogos de determinado tipo num array de jogos
*/
int ContaJogosArray(Jogo v[], int size, char tipo) {
	int c = 0;	//contador
	//h1
	for (int i = 0; i < size; i++) {
		if (v[i].tipo == tipo) {
			c++;
		}
	}
	//h2
	/*int i = 0;
	while (i < size) {
		if (v[i].tipo == tipo) {
			c++;
		}
		i++;
	}*/
	return c;
}

#pragma endregion