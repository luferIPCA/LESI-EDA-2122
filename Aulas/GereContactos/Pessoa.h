/**
*  @file Pessoa.h
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Dados globais para uma Lista Ligada Simples de Pessoas
 * @bug No known bugs.
*/
#pragma once
#include <stdio.h>
#include "Contatos.h"

#define M 40
/**
* @brief Informação de uma pessoa
*/
typedef struct Pessoa {
	int nc;			/**< Número de Contribuinte*/
	char nome[M];	/**< Nome da Pessoa */
}Pessoa;

/**
* @brief Lista de Pessoas
* Informação sobre a Pessoa, os seus contactos e apontador para outra Pessoa
*/
typedef struct ListaPessoa {
	struct Pessoa ficha;	/**< toda a informação da Pessoa */
	struct ListaContactos* contactos;	/**< Todos os contactos da Pessoa*/
	struct ListaPessoa* prox;	/**< Ligação a outra pessoa*/
}ListaPessoa;

Pessoa* CriaPessoa(char* nome, int nc);
ListaPessoa* CriaNodoListaPessoas(Pessoa* c);
ListaPessoa* InserePessoaListaPessoas(ListaPessoa* h, Pessoa* p);

ListaPessoa* ProcuraPessoa(ListaPessoa* inicio, int nc);
void MostraTodasPessoas(ListaPessoa* h);


void MostraContactosPessoa(ListaPessoa* inicio, int nc);
ListaPessoa* InsereContactoPessoa(ListaPessoa* h, Contacto* c, int nc);