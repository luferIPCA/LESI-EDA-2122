/**
*  @file Maquinas.c
 * @author lufer
 * @email lufer@ipca.pt
 * @date 2022
 * @brief Lista Ligadas Simples 
 *
 *	Funções para Manipulação de Lista Ligada Simples de Máquinas

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 *
 * @bug bugs desconhecidos.
*/

#include "Maquinas.h"

/**
 * @brief .
 * 
 * @param novoCod
 * @param novoNome
 * @return 
 */
Maquina *CriaMaquina(int novoCod, char*novoNome) {
	//aloca espaço de memória
	Maquina *nova = (Maquina*) malloc(sizeof(Maquina));
	nova->cod = novoCod;
	strcpy(nova->nome, novoNome);
	nova->prox = NULL;
	return nova;
}

/**
*	@brief Insere maquina na lista
*	@param [in] h		inicio da lista
*	@param [in] nova	nova maquina a inserir
*	@return		Inicio da Lista
*/
Maquina* InsereMaquina(Maquina* h, Maquina* nova) {
	
	if (nova == NULL)	//se nova vem a nulo
		return h;	
	if (h == NULL) {	//lista vazia
		h = nova;
		return (h);
	}
	/*else{		//insere sempre no inicio
		nova->prox = h;
		h = nova;
	}*/

	//else {	//insere sempre no fim
	//	Maquina* aux = h;
	//	while (aux->prox != NULL) aux = aux->prox;
	//	aux->prox = nova;
	//}
	else {		//insere ordenado (inicio, meio, fim)
		Maquina* aux = h;
		Maquina* antAux = aux;
		while (aux != NULL && aux->cod < nova->cod) {
			antAux = aux;
			aux = aux->prox;
		}
		if (aux == h) {		//insere antes do inicio
			nova->prox = h;
			h = nova;
			return h;
		}
		if (aux != NULL)	//insere no meio ou fim
		{
			nova->prox = aux;
			antAux->prox = nova;
		}
	}
	return h;
}

/**
* @brief Função que procura uma máquina pelo seu id
* Fábio Rodrigues Nº20079 2ºAno
*/
Maquina* ProcuraMaquina(Maquina* maquina, int cod)
{
	Maquina* auxMaquinas = NULL;
	Maquina* auxMaquinas2 = NULL;
	if (maquina != NULL)
	{
		if (maquina->cod == cod)
		{
			auxMaquinas2 = CriaMaquina(maquina->cod, maquina->nome);

			auxMaquinas = InsereMaquina(auxMaquinas, auxMaquinas2);
		}

		maquina = maquina->prox;
	}

	return auxMaquinas;
}

bool ComparaMaquinas(Maquina* a, Maquina* b) {
	if (strcmp(a->nome, b->nome) == 0) return true;
	return false;
}

int ContaMaquinas(Maquina* a, char* nome, bool(*p)(void* v1, void*v2)) {
	int tot = 0;
	Maquina* aux = a;
	if (a == NULL) return 0;
	while (aux) {
		if ((*p)(aux->nome, nome) == 0) tot++;
		aux = aux->prox;
	}
	return tot;
}