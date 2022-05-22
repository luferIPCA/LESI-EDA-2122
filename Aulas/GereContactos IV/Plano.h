/*****************************************************************//**
 * @file   Plano.h
 * @brief  Planeamento
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#pragma once

#include <stdbool.h>

#define M 7
#define T 100

/**
 * .
 */
typedef struct CelulaPlano {
	int codJob;
	int codOper;
	int duracao;	//para simplificar trabalha-se com valorees temporais inteiros
}CelulaPlano;


CelulaPlano Plano[M][T];
//CelulaPlano c[2][3] = {{1, 3, 0}, {2, 5, 9}};

bool Ocupa(int job, int oper, int maq, int t);