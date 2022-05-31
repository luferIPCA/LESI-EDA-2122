/**
*  @file Maquinas.c
 * @author lufer
 * @email lufer@ipca.pt
 * @date 2022
 * @brief Lista Ligadas Simples 
 *
 *	Funções para Manipulação de Lista Ligada Simples de Máquinas

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 *
 * @bug bugs desconhecidos.
*/

#include "Maquinas.h"
#include "Jobs.h"

/**
 * @brief .
 * 
 * @param novoCod
 * @param novoNome
 * @return 
 */
Maquina *CriaMaquina(int novoCod, char*novoNome) {
	//aloca espaço de memória
	Maquina *nova = (Maquina*) malloc(sizeof(Maquina));
	nova->cod = novoCod;
	strcpy(nova->nome, novoNome);
	nova->prox = NULL;
	return nova;
}

/**
*	@brief Insere maquina na lista
*	@param [in] h		inicio da lista
*	@param [in] nova	nova maquina a inserir
*	@return		Inicio da Lista
*/
Maquina* InsereMaquina(Maquina* h, Maquina* nova) {
	
	if (nova == NULL)	//se nova vem a nulo
		return h;	
	if (h == NULL) {	//lista vazia
		h = nova;
		return (h);
	}
	/*else{		//insere sempre no inicio
		nova->prox = h;
		h = nova;
	}*/

	//else {	//insere sempre no fim
	//	Maquina* aux = h;
	//	while (aux->prox != NULL) aux = aux->prox;
	//	aux->prox = nova;
	//}
	else {		//insere ordenado (inicio, meio, fim)
		Maquina* aux = h;
		Maquina* antAux = aux;
		while (aux != NULL && aux->cod < nova->cod) {
			antAux = aux;
			aux = aux->prox;
		}
		if (aux == h) {		//insere antes do inicio
			nova->prox = h;
			h = nova;
			return h;
		}
		if (aux != NULL)	//insere no meio ou fim
		{
			nova->prox = aux;
			antAux->prox = nova;
		}
	}
	return h;
}

/**
* @brief Função que procura uma máquina pelo seu id
* Fábio Rodrigues Nº20079 2ºAno
*/
Maquina* ProcuraMaquina(Maquina* maquina, int cod)
{
	Maquina* auxMaquinas = NULL;
	Maquina* auxMaquinas2 = NULL;
	if (maquina != NULL)
	{
		if (maquina->cod == cod)
		{
			auxMaquinas2 = CriaMaquina(maquina->cod, maquina->nome);

			auxMaquinas = InsereMaquina(auxMaquinas, auxMaquinas2);
		}

		maquina = maquina->prox;
	}

	return auxMaquinas;
}

bool ComparaMaquinas(Maquina* a, Maquina* b) {
	if (strcmp(a->nome, b->nome) == 0) return true;
	return false;
}

int ContaMaquinas(Maquina* a, char* nome, bool(*p)(void* v1, void*v2)) {
	int tot = 0;
	Maquina* aux = a;
	if (a == NULL) return 0;
	while (aux) {
		if ((*p)(aux->nome, nome) == 0) tot++;
		aux = aux->prox;
	}
	return tot;
}

#pragma region JOBS_OPER_MAQ
/*
* Manipulação Ficheiros Binarios a partir da Lista
*/
bool SaveOper(Operacao* h, int codJob, FILE* fp) {
	Operacao* aux = h;
	JobFile cel;

	while (aux != NULL) {
		cel.o = aux->o;
		cel.j = codJob;
		Maq* maquinas = aux->maquinas;
		while (maquinas) {
			cel.m = maquinas->m;
			cel.t = maquinas->t;
			fwrite(&cel, sizeof(JobFile), 1, fp);
			maquinas = maquinas->next;
		}
		aux = aux->next;
	}
}

bool SaveAllJobs(char* FileName, Job* h) {
	FILE* fp;
	//fp = fopen();

	Job* aux = h;
	bool aux = SaveOper(h->opers, aux->j, fp);

	fclose(fp);
}

bool SaveJob(Job* j, FILE* fp) {
	Operacao* aux = j->opers;
	JobFile cel;

	cel.j = j->j;
	//Percorre todas as operações deste job
	while (aux != NULL) {
		cel.o = aux->o;
		Maq* maquinas = aux->maquinas;
		//Percorre todas as maquinas desta operação
		while (maquinas) {
			cel.m = maquinas->m;
			cel.t = maquinas->t;
			fwrite(&cel, sizeof(JobFile), 1, fp);
			maquinas = maquinas->next;
		}
		aux = aux->next;
	}
}

#pragma region TREE
/*
* Manipulação Ficheiros Binarios a partir da Arvore
*/
bool SaveTreeJobsPreOrder(TreeJob* r, FILE* fp) {
	if (r == NULL) return false;
	//preOrder
	return SaveJob(r->j, fp);
	SaveTreeJobsPreOrder(r->left, fp);
	SaveTreeJobsPreOrder(r->right, fp);
}

bool SaveTreeJobs(TreeJob* r, char* fileName) {
	if (r == NULL) return false;
	FILE* fp;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return false;
	SaveTreeJobsPreOrder(r, fp);
	fclose(fp);
	return true;
}

TreeJob* GetAll(char* fileName) {
	FILE* fp = fopen(fileName, "rb");
	if (!fp) return NULL;
	JobFile aux;
	TreeJob* root = NULL;

	while (fread(&aux, sizeof(JobFile), 1, fp)!=EOF) {
		//novoJob = Criar nodo de arvore
		//r = InsereNodoTree(r,novoJob)
		//novaOper = Criar node de operacao
		//root->j->opers = InsereOperacaoJob(j->opers, novaOper);
		//novaMaquina = Cria node de Maquina;
		//root->j->opers = InsereMaquinaOperacoesJob(root->j->opers, aux.o, novaMaquina);
	}

	return root;
}

#pragma endregion

#pragma endregion
