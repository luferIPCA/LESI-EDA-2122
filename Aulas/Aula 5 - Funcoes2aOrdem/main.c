/*****************************************************************//**
 * @file   main.c
 * @brief  Funções de 2a Ordem
 * 
 * @author lufer
 * @date   April 2022
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funcoes.h"

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS


// Procedimento principal
void main()
{

#pragma region Funcos2aOrdem

	//inicializar o apontador (g) para a função Dobro
    int (*g)(int a);    //declarar variável...!!!


    g = Dobro;          //g fica a apontar para a função Dobro!
    //chamar a função
    int x = g(12);

    //chamar a função
    int b = VariasFuncoes(g(120));

    g = Factorial;
    int f = VariasFuncoes(g(5));

#pragma endregion

}
