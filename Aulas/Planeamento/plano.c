/*****************************************************************//**
 * @file   plano.c
 * @brief  Manipulação de um Plano de Produção
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#include <stdio.h>
#include "plano.h"

void IniciaPlano(Cel p[][T], int codJob, int codOper) {

	for (int l = 0; l < M; l++)
		for (int col = 0; col < T; col++) {
			p[l][col].idJob = codJob;
			p[l][col].idOper = codOper;
		}
}

/**
 * @brief Ocupa uma unidade de tempo do Plano.
 * 
 * @param p		Plano
 * @param mId	Maquina
 * @param t		Tempo
 * @param codJob	Job
 * @param codOper	Operacao
 */
void OcupaUm(Cel p[][T], int mId, int t, int codJob, int codOper) {
	//testar
	p[mId][t].idJob = codJob;
	p[mId][t].idOper = codOper;
}

/**
 * @brief Ocupa várias unidades de tempo.
 * 
 * @param p	- Plano
 * @param mId	- Maquina
 * @param totTempo	- Tempo a ocupar
 * @param c	- Job e Operacao
 */
void OcupaVarios(Cel p[][T], int mId, int totTempo, Cel* c) {
	
	//Fase 1: Procurar a primeira "casa" livre
	int col = 0;
	while (p[mId][col].idJob != -1)
		col++;

	//Fase 1 - Ocupa a partir da posição livre encontrada
	totTempo += col;	//porquê?
	for (; col < totTempo; col++) {
		p[mId][col].idJob = c->idJob;
		p[mId][col].idOper = c->idOper;
		//p[mId][col] = *c;
	}

	//Fase 2 - Procurar quando a operação anterior

	//Fase 3 - Verficar se após posição livre existe tempo suficiente...
}

Ocupa(Cel p[][T], int mId, int totTempo, int codJ, int codO) {
	Cel c = { .idJob=codJ, .idOper=codO };
	OcupaVarios(p, mId, totTempo, &c);
}


bool SavePlan(char* fileName, Cel p[][T]);

Cel** GetPlan(char* fileName);

/**
 * @brief Carrega dados de um ficheiro CSV.
 * 
 * @param fileName
 * @return 
 */
Job* CarregarDadosFicheiro(char* fileName) {
	FILE* fp;
	char texto[MAX];
	int a, b, c, d;

	Job *listaJobs = NULL;

	Job auxJob;
	Oper auxOper;
	Maquina auxMaq;

	//char d[20];

	fp = fopen(fileName, "r");
	if (fp == NULL) return;

	while (!feof(fp)) {
		//fgets
		//fscanf()
		if (fgets(texto, MAX, fp) != NULL)
		{
			//printf("Texto: %s\n", texto);
			//analisar o texto do ficheiro
			//3333;sddfsds;224;3434
			//sscanf(texto, "%d;%[^;];%d;%d", &a, d, &b, &c);
			sscanf(texto, "%d;%d;%d;%d", &auxJob.codJob, &auxOper.cod, &auxMaq.codM, &auxMaq.t);
			printf("LIDO: %d - %d - %d - %d \n", auxJob.codJob, auxOper.cod, auxMaq.codM, auxMaq.t);
			/*
			if(ProcuraJob(listaJobs,auxJob.codJob)==NULL)
				listaJobs = InsereJob(listaJobs, auxJob);
			if(ProcuraOperacaoJob(listaJobs, auxOper.cod)==NULL)
				listaJobs = InsereOperacaoJob(listaJobs, auxJob.codJob, auxOper);
			listaJobs = InsereMaquinaOperacaoJob(listaJobs, auxJob.codJob, auxOper.cod, auxMaq);
			*/
		}
	}
	fclose(fp);
	return listaJobs;
}

