/**
*  @file Contactos.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Contactos
 * @bug No known bugs.
*/

#include "Contatos.h"

/**
*/
Contacto* CriaContacto(char* desc, char* valor) {
	Contacto* aux = (Contacto*)calloc(1, sizeof(Contacto));
	strcpy(aux->desc, desc);
	strcpy(aux->valor, valor);
	return aux;
}

/**
* @brief Cria novo nodo para a Lista de Contactos
* Copia para o nodo da lista a informação de um contacto
* @param [in] c	Novo contacto
* @param [out] Apontador para nodo criado
*/
ListaContactos* CriaNodoListaContactos(Contacto* c) {
	ListaContactos* novo = (ListaContactos*)calloc(1, sizeof(ListaContactos));
	strcpy(novo->contacto.desc, c->desc);
	strcpy(novo->contacto.valor, c->valor);
	novo->prox = NULL;
	return novo;
}

/**
* @brief Insere um novo contacto na lista
*/
ListaContactos* InsereContactoListaContactos(ListaContactos* h, Contacto* novoContacto) {
	if (novoContacto == NULL)	return h;	//se novo está vazio
	//Cria novo nodo da lista de contactos
	ListaContactos* novo = CriaNodoListaContactos(novoContacto);
	if (h == NULL) h = novo;		//se lista está vazia
	else {
		//Assumir que se insere sempre no inicio
		novo->prox = h;
		h = novo;
	}
	return h;
}

/**
*/
void MostraContactos(ListaContactos* h) {
	ListaContactos* aux = h;
	while (aux) {
		printf("Contacto: %s - Valor: %s\n", aux->contacto.desc, aux->contacto.valor);
		aux = aux->prox;
	}

}
