/*
	Name:
	Author: lufer
	Date: 2022
	Description:
		- Manipulação de Ficheiros
		- Exploração para Trabalho Prático
	
	Parsing de ficheiros de texto:
		fscanf
		sscanf
		strtok
	Ver: 
	https://www.tutorialspoint.com/cprogramming/c_file_io.htm
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#pragma warning (disable: 4996)

#define TAM 1000			

//-------------------------------------------------------------------------

int main() {
	setlocale(LC_ALL, "Portuguese");
	char c[TAM];

	FILE* fp = NULL;					//handler de ficheiro de entrada
	fp = fopen("FicheiroDados.txt", "r"); // abrir frases.txt em modo leitura

	//se houve algum problema...
	if (fp == NULL) {
		perror("Erro ao abrir o ficheiro\n");
		getche();
		return(-1);
	}


	int l = 1;		//conta linhas lidas
	int linOper=0;
	while (fscanf(fp, "%[^\n] ", c) != EOF) {	//lê até ao fim da linha
		printf("File:\n%s\n", c);
		if (l == 1)
		{
			int proc, maq, oper;
			int x = sscanf(c, "%dx%dx%d", &proc, &oper, &maq);
			printf("Proc: %d, Oper: %d, Maq: %d\n", proc,oper, maq);
			l++;
			continue;
		}
		if (l == 2) {
			char s[40];
			int numOper;
			int x = sscanf(c, "%s%*c%d",s , &numOper);	//%*c...encontra o char e não guarda!!!
			printf("Proc: %s, Oper: %d\n", s, numOper);
			l++;
			linOper= numOper;
			continue;
		}
		if (linOper > 0) {
			int m, t;
			char* field;
			field = strtok(c, "-");
			while (field != NULL) {
				printf("%s\n", field);
				field = strtok(NULL, "-");
			}
			//sscanf(c, "%*c%d%*c%d", &m, &t);
			//printf("Maq: %d, Tempo: %d\n", m, t);
			linOper--;
			continue;
		}
	}
	fclose(fp);
}
