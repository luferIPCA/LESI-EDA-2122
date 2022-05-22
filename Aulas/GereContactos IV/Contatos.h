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
#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define M 40
#define N 40

#pragma region GereContactos

typedef struct Contacto {
	char desc[M];		/**< designação do contacto. ex: Telefone*/
	char valor[N];		/**< Valor do contacto. ex: 88997788*/
}Contacto;

typedef struct ListaContactos {
	struct Contacto contacto;
	struct ListaContactos* proxContacto;
}ListaContactos;


Contacto* CriaContacto(char* desc, char* valor);
void MostraContactos(ListaContactos* h);
ListaContactos* InsereContactoListaContactos(ListaContactos* h, Contacto* novo);
ListaContactos* CriaNodoListaContactos(Contacto* c);

#pragma endregion
