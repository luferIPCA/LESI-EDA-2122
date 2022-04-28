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
	//Element* p = (Element*)e;
	//Pessoa* q = (Pessoa*)p->data;
	node->element.data = ((Element*)e)->data;
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
		//Element* p = (Element*)e;
		//Pessoa* q = (Pessoa*)p->data;
		root = NewNode(e);
		return root;
	}
	//((Element*)e)->data
	//Element* p = (Element*)e;
	//Pessoa* q = (Pessoa*)p->data;
	//Pessoa* q1 = (Pessoa*)root->element.data;

	if ((*comp)(root->element.data, ((Element*)e)->data)>0) {
		root = AddNode(root->leftTree, e, comp);
	}
	else
		root = AddNode(root->rightTree, e,comp);
	return root;
}

void ShowTree(Node* root, void (*show)(void* data)) {
	if (root == NULL) return;
	(*show)(root->element.data);
	ShowTree(root->leftTree, show);
	ShowTree(root->rightTree, show);
}


