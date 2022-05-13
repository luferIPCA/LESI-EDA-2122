/*****************************************************************//**
 * @file   HistoricoABP.c
 * @brief  Registo das pessoas que foram removidas
 * 
 * @author lufer
 * @date   April 2022
 *********************************************************************/

#include "GenericaABP.h"
#include "Pessoa.h"

Node* InitTree() {
	return NULL;
}

Node* NewNode(void* e) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return NULL;	//problemas ao criar espaço em memória	
	node->element.data = e;
	node->leftTree = NULL;
	node->rightTree = NULL;
	return node;
}

/**
 * @brief .
 * 
 * @param root
 * @param e
 */
Node* AddNode(Node* root, void* e, int (*comp)(void* a, void* b)) {
	if (root == NULL) {
		root = NewNode(e);
		return root;
	}
	if ((*comp)(root->element.data, e)>0) {
		root->leftTree = AddNode(root->leftTree, e, comp);
	}
	else
		root->rightTree = AddNode(root->rightTree, e,comp);
	return root;
}

void ShowTree(Node* root, void (*a)(void* data)) {
	if (root == NULL) return;
	(*a)(root->element.data);		//pre-order
	ShowTree(root->leftTree, a);
	ShowTree(root->rightTree, a);
}

/**
 * @brief Preservar informação da árvore em ficheiro
 * @url		https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
 *			Versão I: Devolve boleano
 * @param root
 * @param fp
 * @return 
 */
bool GuardaArvoreII(Node* root, FILE * fp) {
	if (fp == NULL) return false;
	if (root == NULL) return true;
	Pessoa aux;
	//aux.data = root->element.data
	aux.nc = ((Pessoa*)(root->element.data))->nc;
	strcpy(aux.nome, ((Pessoa*)(root->element.data))->nome);
	//Pre-Order
	fwrite(&aux, sizeof(aux), 1, fp);
	return (GuardaArvoreII(root->leftTree, fp) && GuardaArvoreII(root->rightTree, fp));
}

/**
 * @brief	Preservar informação da árvore em ficheiro.
 *			Versão II: não devolve nada!
 * @param root
 * @param fp
 */
void GuardaArvore(Node* root, FILE* fp) {
	if (root == NULL) return true;
	Pessoa aux = { .nc = 0,.nome = "" };
	//aux.data = root->element.data
	aux.nc = ((Pessoa*)(root->element.data))->nc;
	strcpy(aux.nome, ((Pessoa*)(root->element.data))->nome);
	//Pre-Order
	fwrite(&aux, sizeof(aux), 1, fp);
	GuardaArvore(root->leftTree, fp);
	GuardaArvore(root->rightTree, fp);
}

/**
 * @brief Preserva informação. Gere Ficheiro e Árvore.
 * 
 * @param root
 * @param fileName
 * @return 
 */
bool GuardaHistorico(Node* root, char* fileName) {
	FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) return false;
	GuardaArvore(root, fp);
	fclose(fp);
	return true;
}

/**
 * @brief Carrega de ficheiro informação para a Árvore.
 * 
 * @param fp
 * @return 
 */
Node* GetArvore(FILE *fp) {
	Node* root = InitTree(); //root=NULL;
	if (fp == NULL) return NULL;
	Pessoa *aux = (Pessoa*)malloc(sizeof(Pessoa));
	while (fread(aux, sizeof(Pessoa), 1, fp)) {
		root = AddNode(root, aux, ComparaNC);
		aux = (Pessoa*)malloc(sizeof(Pessoa));
	}
	return root;
}

/**
 * @brief Carrega informação. Gere Ficheiro e Árvore
 * 
 * @param fileName
 * @return 
 */
Node* GetHistorico(char* fileName) {
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) return false;
	Node* aux = GetArvore(fp);
	fclose(fp);
	return aux;
}


