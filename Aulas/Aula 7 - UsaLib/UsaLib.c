/**
Uso de Bibliotecas
*/
#include <stdio.h>
#include "c:\temp\Funcoes.h"

int x = 10;

/// <summary>
/// Função Recursiva
/// </summary>
/// <param name="y"></param>
/// <returns></returns>
int Aux(int y) {
	static int f = 0;
	if (y > 0) {
		f += y;
		//y++;
		x++;
		y--;
		return Aux(y);
	}	
	else
		return(f);
}



int main() {

	//extern int x;

	int aux = Soma(12, 13);

	printf("%d\n", x);

	int x1 = Aux(3);

	printf("X=%d - Y=%d", x, Aux(12));



}


