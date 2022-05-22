/*
lufer@ipca.pt
Implementação de Árvores Binárias Balanceadas (AVL)
*/
#include <stdio.h>
#include "AVLtree.h"

/*
Devolve a altura de um nodo
*/
unsigned int AVLHeight(PtrAVLNode root) {
	if (root == NULL) return 0;
	return (root->height);
}

/*
(Balance Factor)
Calcula o Factor de Balanceamento de um nodo
*/
unsigned int BF(PtrAVLNode root) {
	if (root == NULL) return 0;
	return (AVLHeight(root->esq) - AVLHeight(root->dir));
}

/*
Balanceia árvore
*/
PtrAVLNode BalanceAVL(PtrAVLNode root) {
	unsigned int hl, hr;

	if (root == NULL) return NULL;
	hl = AVLHeight(root->esq);
	hr = AVLHeight(root->dir);
	if (hl - hr == 2)  //subarvore esquerda desbalanceada
	{
		//Balanceia Esquerda
	}
	else
	{
		if (hr - hl == 2)  //subarvore direita desbalanceada
		{
			//Balanceia Direita
		}
	}
	return root;
}