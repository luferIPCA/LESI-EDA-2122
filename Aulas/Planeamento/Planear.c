/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Contactos
 * @bug No known bugs.
*/

#include "plano.h"
#include  <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Job* listaJobs;
	
	listaJobs=CarregarDadosFicheiro("Dados.csv");
	
	#pragma region ESCALONAMENTO

	Cel plano[M][T];
	IniciaPlano(plano, -1, -1);
	OcupaUm(plano, 0, 0, 2, 4);

	Cel aux;
	aux.idJob = 1;
	aux.idOper = 1;

	//j1;o1;m1;3
	aux.idJob = 1;
	aux.idOper = 1;
	OcupaVarios(plano, 0, 6, &aux);
	//j1;o2;m4;6
	aux.idJob = 1;
	aux.idOper = 1;
	OcupaVarios(plano, 0, 6, &aux);

	Ocupa(plano, 2, 3,1,2);


#pragma endregion


}