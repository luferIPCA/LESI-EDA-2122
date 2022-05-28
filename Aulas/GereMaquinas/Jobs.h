/*****************************************************************//**
 * @file   Jobs.h
 * @brief  
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#pragma once


typedef struct Maq
{
	int m;
	float t;
	struct Maq* next;
}Maq;

typedef struct Operacao {
	int o;
	struct Operacao* next;
	struct Maq* maquinas;
}Operacao;

typedef struct Job {
	int j;
	struct Operacao* opers;
}Job;

typedef struct JobFile {
	int j;
	int o;
	int m;
	float t;
}JobFile;

typedef struct TreeJob {
	Job* j;
	struct TreeJob* left;
	struct TreeJob* right;
}TreeJob;

bool SaveOper(Operacao* h, int codJob, FILE* fp);
bool SaveAllJobs(char* FileName, Job* h);
bool SaveJob(Job* j, FILE* fp);
bool SaveTreeJobsPreOrder(TreeJob* r, FILE* fp);
bool SaveTreeJobs(TreeJob* r, char* fileName);