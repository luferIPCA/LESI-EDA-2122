/**
*  @file Pessoas.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Pessoas
 * @bug No known bugs.
*/
#include "Pessoa.h"
#include "Contatos.h"



Pessoa* CriaPessoa(char* nome, int nc) {
	Pessoa* aux = (Pessoa*)calloc(1, sizeof(Pessoa));
	aux->nc = nc;
	strcpy(aux->nome, nome);
	return aux;
}
/**
* @brief Cria novo nodo para a Lista de Pessoas
* Copia para o nodo da lista a informação de uma pessoa
* @param [in] c	Novo contacto
* @param [out] Apontador para nodo criado
*/
ListaPessoa* CriaNodoListaPessoas(Pessoa* c) {
	ListaPessoa* nova = (ListaPessoa*)calloc(1, sizeof(ListaPessoa));
	nova->ficha.nc=c->nc;
	strcpy(nova->ficha.nome, c->nome);
	nova->contactos = NULL;	// no início não tem contactos
	nova->prox = NULL;
	return nova;
}

/**
* @brief Insere pessoa na Lista de Pessoas
* @param [in] p	Nova pessoa
* @param [in] Apontador para inicio da lista
* @param [out] Apontador para inicio da lista
*/
ListaPessoa* InserePessoaListaPessoas(ListaPessoa* h, Pessoa* p) {
	if (p == NULL) return h;	//se nova não tem dados
	//Cria novo nodo da lista de pessoas
	ListaPessoa* nova = CriaNodoListaPessoas(p);
	if (h == NULL) h = nova;	//se lista é vazia
	else {					//	insere ordenado pelo nc
		nova->prox = h;
		h = nova;
	}
	return h;
}

/**
*/
ListaPessoa* ProcuraPessoa(ListaPessoa* inicio, int nc) {
	ListaPessoa* aux = inicio;
	while (aux) {
		if (aux->ficha.nc == nc) return aux;	//se encontrou
		aux = aux->prox;
	}
	return NULL;			//se não encontrou
}

/**
*/
ListaPessoa* InsereContactoPessoa(ListaPessoa* h, Contacto* c, int nc) {
	if (h == NULL) return NULL;	// se lista vazia
	if (c == NULL) return h;	//se contacto não tem informação
	
	ListaPessoa* aux = ProcuraPessoa(h, nc);
	if (aux) {		//se existe essa pessoa
		aux->contactos = InsereContactoListaContactos(aux->contactos, c);
	}
	return h;
}

/**
*/
void MostraTodasPessoas(ListaPessoa* h) {
	ListaPessoa* aux = h;
	while (aux) {
		printf("Pessoa: NC=%d - Nome= %s\n", aux->ficha.nc, aux->ficha.nome);
		aux = aux->prox;
	}
}

/**
*/
void MostraContactosPessoa(ListaPessoa* inicio, int nc) {
	ListaPessoa* aux = inicio;
	aux = ProcuraPessoa(inicio, nc);
	if (aux) {
		ListaContactos* inicioContactos = aux->contactos;
		printf("Pessoa: %d\n", aux->ficha.nc);
		MostraContactos(inicioContactos);
	}
}


