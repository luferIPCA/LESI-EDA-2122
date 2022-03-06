/*
autor:lufer
UC: Programação
desc: Calculadora básica
date
email
vers
*/
#include <stdio.h>
#include <conio.h>
#include "Funcoes.h"

int main() {
	int x, y;

	//simular dados
	x = 23;
	y = 34;

	//mostrar resultados
	printf("%d + %d = %d\n", x, y, soma(x, y));
	
	printf("Maior entre %d e %d = %d\n", x, y, maior(x, y));

}
