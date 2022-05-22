/*****************************************************************//**
 * @file   plano.h
 * @brief  
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#pragma once
#pragma warning (disable: 4996)
#define M 4		//Número de Máquinas
#define T 10	//Número de Tempos
#define MAX 100

typedef struct Maquina {
	int codM;
	int t;
	struct Maquina* next;
}Maquina;

typedef struct Oper {
	int cod;
	struct Maquina* maquinas;
	struct Oper* next;
}Oper;

typedef struct Job {
	int codJob;
	Oper* operacoes;
}Job;



typedef struct Cel {
	int idJob;
	int idOper;
} Cel;

void IniciaPlano(Cel p[][T], int codJob, int codOper);
void OcupaUm(Cel p[][T], int mId, int t, int codJob, int codOper);
void OcupaVarios(Cel p[][T], int mId, int totTempo, Cel* c);

