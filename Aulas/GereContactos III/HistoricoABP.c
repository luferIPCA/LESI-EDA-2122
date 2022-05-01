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

void ShowTree(Node* root, void (*show)(void* data)) {
	if (root == NULL) return;
	(*show)(root->element.data);		//pre-order
	ShowTree(root->leftTree, show);
	ShowTree(root->rightTree, show);
}


