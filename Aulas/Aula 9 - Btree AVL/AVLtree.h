/*
Árvores AVL - Adelson, Velski & Landis
lufer@ipca.pt
*/
#include "btree.h"

#ifndef AVLTREE
#define AVLTREE

// ================== AVL Tree ================
/*
AVL Tree - Adelson, Velski & Landis
*/

typedef struct AVLNode {
	Element val;
	struct avlNode *esq, *dir;
	unsigned int height;		
}AVLNode;

typedef AVLNode *PtrAVLNode;

// =============== MÉTODOS ================
unsigned int AVLHeight(PtrAVLNode root);
unsigned int BF(PtrAVLNode root);
PtrAVLNode BalanceAVL(PtrAVLNode root);
//calcular número de elementos
//mostrar a árvore
//Valor no nodo X
//Destruir a árvore
//Maior elemento
//Menor elemento
//Travessias
#endif