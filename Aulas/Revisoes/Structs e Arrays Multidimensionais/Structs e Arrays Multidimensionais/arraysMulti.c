/*
Funções para manipular arrays multidimensionais
lufer@ipca.pt
Ver: https://beginnersbook.com/2014/01/2d-arrays-in-c-example/
*/

#include "arraysMulti.h"



/*
Mostra o conteúdo de um array bidimensional
*/
void mostraArrayBidimensional(int v[][N], int t) {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < N; j++) {
			printf("v[%d][%d]=%d | ", i, j, v[i][j]);
		}
		printf("\n");
	}
}

/*
inicializa array bidimensional com determinado valor
*/
void inicalizaArrayBidimensional(int v[][N], int t, int valor) {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = valor;
		}
	}
}

void ShowArrayDuplo(int rows, int cols, int* a) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
				printf("%d ", a[i * cols + j]);
		}
		printf("\n");	
	}
}

/**
 * @brief Mostar array duplo, passado como pointer.
 * 
 * @param v
 * @param n
 * @param m
 */
void ShowArrayDuploII(int(*v)[][2], int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d\n", (*v)[i][j]);
}

/**
 * @brief Mostar array duplo.
 * 
 * @param a
 * @param n
 * @param m
 */
void ShowArrayDuploIII(int(*a)[2], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("array[%d][%d]=%d\n", i, j, a[i][j]);
		}
	}
}


void ShowArrayDuploIV(int** a, int n, int m){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
/**
 * @brief Altera o valor de uma posição do array.
 * 
 * @param a
 * @param n
 * @param m
 * @param v
 */
void ChangeValue(int(*a)[2], int n, int m, int v)
{
	//a[n][m] = v;
	*(a)[m]= v;
}
