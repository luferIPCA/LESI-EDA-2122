/*****************************************************************//**
 * @file   Funcoes.h
 * @brief  
 * Funções de 2a Ordem
 * Funções recebem funções como parâmetro
 * Apontadores para funções
 * (type) (*pointerName)(parameter);
 *   type: tipo que a função retorna;
 *   pointerName: apontador para a função;
 *   parameter: lista de parâmetros passados para a função
 * @author lufer
 * @date   April 2022
 *********************************************************************/
#pragma once


//Assinaturas comuns: 
int Dobro(int x);		// Dobro é função que devolve um int
float Media(int x[], int n);
int Factorial(int x);

/**
* @brief: Assinatura de função que recebe como parâmetro um apontador para função....
*/
int VariasFuncoes(int (*g)(int a));

//EXEMPLOS:
// g é apontador para uma função que recebe um inteiro e devolve um inteiro 
//int (*g)(int a); 
