/**
*  @file Maquinas.h
 * @author lufer
 * @email lufer@ipca.pt
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 *	Definições globais: constantes, Tipos e Assinaturas de funções

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 *
 * @bug bugs desconhecidos.
*/

#ifndef MAQUINA

#include <stdio.h>

#define M 40
typedef struct Maquina {
	int cod;
	char nome[M];
	struct Maquina* prox;
}Maquina;

//cria nova maquina
Maquina* CriaMaquina(int novoCod, char* novoNome);
Maquina* InsereMaquina(Maquina* h, Maquina* nova);


#define MAQUINA 
#endif
