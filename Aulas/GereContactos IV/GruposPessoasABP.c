/*****************************************************************//**
 * @file   GruposPessoasABP.c
 * @brief  Gere Grupos de Pessoas com uma ABP
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/

#include "GruposABP.h"
#include "Pessoa.h"

#include <stdio.h>

#pragma region GereGruposPessoas
/**
 * @brief .
 * 
 * @param cod
 * @param h
 * @return 
 */
GrupoPessoas* CriaGrupoPessoas(int cod, ListaPessoa* h) {
	GrupoPessoas* aux = (GrupoPessoas*)calloc(1, sizeof(GrupoPessoas));
	if (aux != NULL) {
		aux->codGrupo = cod;
		aux->pessoas = h;
	}
	return aux;
}

/**
 * @brief Insere um Contacto numa Pessoa de um determinado grupo.
 * 
 * @param r
 * @param codGrupo
 * @param nc
 * @param c
 * @return 
 */
NodeTree* InsereContactoPessoaGrupo(NodeTree* r, int codGrupo, int nc, Contacto* c) {
	NodeTree* aux = SearchNodeTree(r, codGrupo);
	if (aux == NULL) return r;
	else
		aux->element->pessoas= InsereContactoPessoa(aux->element->pessoas, c, nc);
	return r;
}

#pragma endregion

#pragma region GereArvore

/**
 * @brief .
 * 
 * @return 
 */
NodeTree *CreateTree() {
	return NULL;
}

/**
 * @brief .
 * 
 * @param g
 * @return 
 */
NodeTree *NewNodeTree(GrupoPessoas *g) {
	NodeTree *aux = (NodeTree*)calloc(1,sizeof(NodeTree));
	if (aux)
	{
		aux->element = g;
		aux->leftNode = aux->rightNode = NULL;
	}
	return aux;
}

/**
 * @brief .
 * 
 * @param root
 * @param g
 * @return 
 */
NodeTree* AddNodeTree(NodeTree* root, GrupoPessoas* g) {
	if (root == NULL)
		root = NewNodeTree(g);
	else
	{
		if (root->element->codGrupo > g->codGrupo)
			root->leftNode = AddNodeTree(root->leftNode, g);
		else
			root->rightNode = AddNodeTree(root->rightNode, g);
	}
	return root;
}

/**
 * .
 */
void ShowNodeTree(NodeTree *root) {
	if (root != NULL) {
		printf("Grupo: %d\n", root->element->codGrupo);
		MostraTodasPessoas(root->element->pessoas);
		ShowNodeTree(root->leftNode);
		ShowNodeTree(root->rightNode);
	}
}

/**
 * @brief Procura um determinado Grupo de Pessoas.
 * 
 * @param r		Raíz da árvore
 * @param codG	Código do Grupo
 * @return 
 */
NodeTree* SearchNodeTree(NodeTree* r, int codG) {
	if (r == NULL) 
		return NULL;
	if (r->element->codGrupo == codG) 
		return r;
	else
		if (r->element->codGrupo > codG)
			return (SearchNodeTree(r->leftNode,codG));
		else
			return (SearchNodeTree(r->rightNode,codG));
}

#pragma endregion




