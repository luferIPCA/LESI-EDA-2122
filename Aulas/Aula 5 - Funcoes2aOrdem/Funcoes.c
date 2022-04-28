/**
* lufer
* Funções de 2a Ordem
* Funções recebem funções como parâmetro
* Apontadores para funções
* (type) (*pointerName)(parameter);  
*   type: tipo que a função retorna;
*   pointerName: apontador para a função;
*   parameter: lista de parâmetros passados para a função
*/

#include "Funcoes.h"

//EXEMPLOS:
// g é apontador para uma função que recebe um inteiro e devolve um inteiro 
//int (*g)(int a); 

/**
* Exemplo de função que recebe um inteiro e devolve um inteiro
*/
int Dobro(int x) {
    return x * 2;
}

float Media(int x[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += x[i];
    }
    return (soma / n);
}

int Factorial(int x) {
    if (x == 0) return 1;
    else
        return (x * Factorial(x - 1));
}

/**
* @brief: Função que recebe como parâmetro um apontador para função....
*/
int VariasFuncoes(int (*g)(int a))
{
    // Chama a função apontada por g
    return g;
}