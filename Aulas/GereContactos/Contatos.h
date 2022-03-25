/**
*  @file Contactos.h
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Dados globais para uma Lista Ligada Simples de Contactos
 * @bug No known bugs.
*/
#pragma once

#include <stdio.h>

#define M 40
#define N 40

typedef struct Contacto {
	char desc[M];		/**< designação do contacto. ex: Telefone*/
	char valor[N];		/**< Valor do contacto. ex: 88997788*/
}Contacto;

typedef struct ListaContactos {
	struct Contacto contacto;
	struct ListaContactos* prox;
}ListaContactos;

Contacto* CriaContacto(char* desc, char* valor);
void MostraContactos(ListaContactos* h);
ListaContactos* InsereContactoListaContactos(ListaContactos* h, Contacto* novo);
ListaContactos* CriaNodoListaContactos(Contacto* c);

