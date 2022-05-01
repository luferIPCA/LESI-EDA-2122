/**
*  @file Pessoas.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Pessoas
 * @bug No known bugs.
*/
#include "Pessoa.h"
#include "Contatos.h"


/**
 * @brief Constroi uma Lista
 * 
 * @return Lista Vazia
 */
Pessoa* CriaLista() {
	return NULL;
}

/**
 * @brief .
 * 
 * @param nome
 * @param nc
 * @return 
 */
Pessoa* CriaPessoa(char* nome, int nc) {
	Pessoa* aux = (Pessoa*)calloc(1, sizeof(Pessoa));
	aux->nc = nc;
	strcpy(aux->nome, nome);
	return aux;
}

/**
* @brief Cria novo nodo para a Lista de Pessoas
* Copia para o nodo da lista a informação de uma pessoa
* @param [in] c	Novo contacto
* @param [out] Apontador para nodo criado
*/
ListaPessoa* CriaNodoListaPessoas(Pessoa* c) {
	ListaPessoa* nova = (ListaPessoa*)calloc(1, sizeof(ListaPessoa));
	nova->fichaPessoa.nc=c->nc;
	strcpy(nova->fichaPessoa.nome, c->nome);
	nova->listaContactos = NULL;	// no início não tem contactos
	nova->proxPessoa = NULL;
	return nova;
}

/**
* @brief Insere pessoa na Lista de Pessoas
* @param [in] p	Nova pessoa
* @param [in] Apontador para inicio da lista
* @param [out] Apontador para inicio da lista
*/
ListaPessoa* InserePessoaListaPessoas(ListaPessoa* h, Pessoa* p) {
	if (p == NULL) return h;	//se nova não tem dados
	//Cria novo nodo da lista de pessoas
	ListaPessoa* nova = CriaNodoListaPessoas(p);
	if (h == NULL) h = nova;	//se lista é vazia
	else {					//	insere ordenado pelo nc
		nova->proxPessoa = h;
		h = nova;
	}
	return h;
}

/**
*/
ListaPessoa* ProcuraPessoa(ListaPessoa* inicio, int nc) {
	ListaPessoa* aux = inicio;
	while (aux) {
		if (aux->fichaPessoa.nc == nc) return aux;	//se encontrou
		aux = aux->proxPessoa;
	}
	return NULL;			//se não encontrou
}

/**
*/
ListaPessoa* InsereContactoPessoa(ListaPessoa* h, Contacto* c, int nc) {
	if (h == NULL) return NULL;	// se lista vazia
	if (c == NULL) return h;	//se contacto não tem informação
	
	ListaPessoa* aux = ProcuraPessoa(h, nc);
	if (aux) {		//se existe essa pessoa
		aux->listaContactos = InsereContactoListaContactos(aux->listaContactos, c);
	}
	return h;
}

/**
*/
void MostraTodasPessoas(ListaPessoa* h) {
	ListaPessoa* aux = h;
	while (aux) {
		printf("Pessoa: NC=%d - Nome= %s\n", aux->fichaPessoa.nc, aux->fichaPessoa.nome);
		aux = aux->proxPessoa;
	}
}

/**
*/
void MostraContactosPessoa(ListaPessoa* inicio, int nc) {
	ListaPessoa* aux = inicio;
	aux = ProcuraPessoa(inicio, nc);
	if (aux) {
		ListaContactos* inicioContactos = aux->listaContactos;
		printf("Pessoa: %d\n", aux->fichaPessoa.nc);
		MostraContactos(inicioContactos);
	}
}



#pragma region GereDataFile

/**
 * @brief Carrega informação sobre Pessoas
 *
 * @param fileName
 * @return  Lista de Pessoas
 */
ListaPessoa* GetAllPessoas(char* fileName) {
	FILE* fp;
	ListaPessoa* h = NULL;
	ListaPessoa* aux;
	Pessoa p;

	if ((fp = fopen(fileName, "rb")) == NULL) return NULL;
	while (fread(&p, sizeof(p), 1, fp)) {
		if (ProcuraPessoa(h, p.nc) == NULL) {//se pessoa ainda não está em memória
			aux = CriaNodoListaPessoas(&p);
			h = InserePessoaListaPessoas(h, aux);
			continue;
		}
	}
	fclose(fp);
	return h;
}

/**
 * @brief Preserva informação da Pessoa
 *
 * @param h
 * @param fileName
 * @return
 */
bool SavePessoas(ListaPessoa* h, char* fileName) {
	if (h == NULL) return false;
	FILE* fp;

	if ((fp = fopen(fileName, "wb")) == NULL) return false;
	ListaPessoa* aux = h;
	while (aux) {
		fwrite(&aux->fichaPessoa, sizeof(aux->fichaPessoa), 1, fp);
		aux = aux->proxPessoa;
	}
	fclose(fp);
	return true;
}


/**
 * @brief Pessoas e respectivos contactos
 * 
 * @param h
 * @param fileName
 * @return 
 */
bool SaveAll(ListaPessoa* h, char* fileName) {
	if (h == NULL) return false;
	FILE* fp;

	if ((fp = fopen(fileName, "wb")) == NULL) return false;

	//grava n registos no ficheiro
	ListaPessoa* aux = h;
	TodaInformacaoPessoa auxFile;	//struct para gravar em ficheiro!
	while (aux) {
		//Colocar no registo de ficheiro a inf que está no registo de memória
		auxFile.nc = aux->fichaPessoa.nc;
		//percore a lista de contactos
		ListaContactos* auxContatos = aux->listaContactos;
		while (auxContatos) {
			strcpy(auxFile.contacto.desc, auxContatos->contacto.desc);
			strcpy(auxFile.contacto.valor, auxContatos->contacto.valor);
			fwrite(&auxFile, sizeof(auxFile), 1, fp);
			auxContatos = auxContatos->proxContacto;
		}
		aux = aux->proxPessoa;
	}
	fclose(fp);
	return true;
}

/**
* Carrega todos os contactos para cada Pessoa
*/
ListaPessoa* GetAll(char* fileName, ListaPessoa* h) {
	FILE* fp;
	ListaPessoa* aux = h;
	Pessoa p;

	if (h == NULL) return NULL;

	if ((fp = fopen(fileName, "rb")) == NULL) return NULL;
	TodaInformacaoPessoa auxFile;
	while (fread(&auxFile, sizeof(auxFile), 1, fp)) {
		//aux = ProcuraPessoa(h, auxFile.nc);
		//ListaPessoa* InsereContactoPessoa(ListaPessoa* h, Contacto* c, int nc)
		h = InsereContactoPessoa(h, &auxFile.contacto, auxFile.nc);
	}
	fclose(fp);
	return h;
}

#define MAX 100

/**
 * @brief Carrega dados de entrada.
 * 
 * @param fileName
 * @return 
 */
ListaPessoa* GetData(char* fileName) {
	FILE* fp;
	ListaPessoa* h = NULL;
	ListaPessoa* aux;	//auxiliar
	Pessoa p;			//auxiliar
	Contacto c;			//auxiliar
	char linhaFicheiro[MAX];

	if ((fp = fopen(fileName, "r")) == NULL) return NULL;
	
	while (fgets(linhaFicheiro,MAX,fp) != NULL)
		{
		//[^0-9]
		//[^a-zA-Z]
		sscanf(linhaFicheiro,"%[^;];%d;%[^;];%s", p.nome, &p.nc, c.desc, c.valor);
	
		if (ProcuraPessoa(h, p.nc) == NULL) {//se pessoa ainda não está em memória
			//Insere Pessoa
			aux = CriaNodoListaPessoas(&p);
			h = InserePessoaListaPessoas(h, aux);
		}
		//Insere contacto
		h = InsereContactoPessoa(h, &c, p.nc);
	}
	fclose(fp);
	return h;
}
#pragma endregion


