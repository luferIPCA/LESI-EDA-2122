/**
*  @file Main.c
 * @author lufer
 * @email lufer@ipca.pt
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 *	Manipulação de Lista Ligada Simples

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 * 
 * @bug bugs desconhecidos.
*/
#include <stdio.h>
#include <locale.h>
#include "Dados.h"

#define MAX 10

int main() {

	setlocale(LC_ALL, "Portuguese");

#pragma region VERSAO 1
	
	//Jogo j1 = {7,"jogo 1",'A'};
	//Jogo j2 = { 9,"jogo 2",'A'};
	//Jogo j3 = { 111,"jogo 3",'T' };

	Jogo *j1 = criaJogo(7, "Jogo1", 'A');
	Jogo *j2 = criaJogo(9,"jogo 2",'A');
	Jogo *j3 = criaJogo(111,"jogo 3",'T');
	Jogo* novo = criaJogo(15, "Outro", 'A');

	Jogo* headLista = NULL;		//inicio da lista
	//Testes de Inserção
	//InsereJogoInicioII(&headLista, j1);			//Funciona!
	//InsereJogoInicioIII(headLista, j1);			//Não funciona!!
	//headLista = InsereJogoInicio(headLista, j1);	//Funciona
	headLista = InsereJogoInicio(headLista, j2);
	headLista = InsereJogoInicio(headLista, j3);
	headLista = InsereJogoInicio(headLista, novo);

	/*headLista = InsereJogoFim(headLista, j1);
	headLista = InsereJogoFim(headLista, j2);
	headLista = InsereJogoFim(headLista, j3);
	headLista = InsereJogoFim(headLista, novo);*/

	MostraLista(headLista);

	headLista=AlteraJogo(headLista, 15, 'K'); 

	novo = criaJogo(150, "OutroJogo", 'T');

	headLista = InsereJogoOrdenado(headLista, novo);
	MostraLista(headLista);

	bool aux = ExisteJogo(headLista, 7);
	aux = false;
	aux = ExisteJogoRecursivo(headLista, 7);
	//Jogo *res = ProcuraJogo(headLista, 111);

	headLista = RemoveJogo(headLista, 15);
	printf("\nApós remover 15");
	MostraLista(headLista);
	getche();

	headLista = RemoveJogo(headLista, 7);
	printf("\nApós remover 7\n");
	MostraLista(headLista);

	Jogo* novaHead = OrdenaLista(headLista);
	MostraLista(novaHead);

	getche();


	/*Utilizar ficheiros*/
	
	bool b = gravarJogoBinario("Dados.bin", headLista);
	DestroiLista(&headLista);


	printf("\nAPOS DESTRUIR LISTA\n");
	headLista = lerJogosBinario("Dados.bin");
	//MostraLista(headLista);

#pragma region FunçãoOrdem2

	//Função de 2a Ordem: Método passa como parâmetro!
	PercorreLista(headLista, &MostraLista);

#pragma endregion

#pragma endregion

	getche();
	return 1;
}

//Outros métodos:
//
//Constroi Lista a partir de Array
//Constroi Lista Recursiva a partir de um array
//Eliminar nodo da lista
//Eliminar todos	
//Procurar nodo

//TPC: Não remover em definitivo...criar um ficheiro de log??

