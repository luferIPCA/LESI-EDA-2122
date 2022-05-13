/**
Uso de Bibliotecas
*/
#include <stdio.h>
#include "c:\temp\Funcoes.h"

int x = 10;


/**
 * @brief Função recursiva local auxiliar
 * 
 * @param y
 * @return 
 */
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


/**
 * @brief Utilização de funções internas e externas (em bibliotecas).
 * 
 * @return 
 */
int main() {

	int aux = Soma(12, 13);	//Soma está implementada na biblioteca externa
	printf("%d\n", x);

	int x1 = Aux(3);		//Aux está implementada neste módulo
	printf("X=%d - Y=%d", x, Aux(12));

}


