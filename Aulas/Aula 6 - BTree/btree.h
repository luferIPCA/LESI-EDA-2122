/*****************************************************************//**
 * @file   btree.h
 * @brief  Árvores Binárias de Procura - (Binary Search Tree )
 * 
 * @author  lufer
 * @email	lufer@ipca.pt
 * @date    April 2022
 *********************************************************************/
/*
Ver:
https://www.geeksforgeeks.org/binary-tree-set-1-introduction/?ref=lbp
*/

#ifndef BTREE
#define BTREE

#define Max(x,y)  ((x>y)? (x) : (y))

typedef   enum Boolean { false, true }   Boolean;

/**
 * Valor do nodo de uma árvore - Elemento.
 */
typedef struct Element {
	int val;
	char* nome;
}Element;

//typedef struct Element Element;


//H1: Nodo da árvore
typedef struct Node {
	Element element;			//struct	
	struct Node *leftTree;
	struct Node *rightTree;
}Node, *PtrNode;

//typedef Node *PtrNode;


//===========================================================
//H2: Nodo da árvore generalizado - informação desacoplada!
typedef struct NodeII {
	Element *element;			//apontador para struct
	struct NodeII *leftTree;
	struct NodeII *rightTree;
}NodeII;

typedef NodeII *PtrNodeII;
//===========================================================

//================= Assinatura de métodos ===================

//Inicializa uma àrvore
PtrNode InitTree();

//Cria novo nodo de uma árvore binária
PtrNode NewNode(Element e);

//Destroi um nodo de uma árvore
void DestroyNode(PtrNode *p);

//Calcula o Número de Nodos de uma Árvore
int TreeSize(PtrNode r);

//Calcula a Altura de uma Árvore
int TreeHeight(PtrNode r);


// =========== Operações de procura ============

PtrNode FindNode(Element e, PtrNode root);

Boolean ExistNode(Element e, PtrNode root);

PtrNode GetMax(PtrNode root);

PtrNode GetMin(PtrNode root);


// =========== Operações de Manipulação ============

PtrNode AddNode(PtrNode root, Element e);
//PtrNode AddNodeII(PtrNode root, Node e);
PtrNode DeleteNode(PtrNode root, Element e);
PtrNode DeleteCurrentNode(PtrNode root);
PtrNode FindMin(PtrNode root);

void PreOrder(PtrNode root);
void PosOrder(PtrNode root);
void InOrder(PtrNode root);

void Show(PtrNode root, int nivel);
void ShowII(char *s);

// =========== Balanceamento ============

PtrNode Balance(PtrNode root);
PtrNode BSTBalance(PtrNode root,Node *list, int ini, int end);
void BST2List(PtrNode root, unsigned int tot, Node *list);


//Folha de Exercicios 10
struct Exp {
	char oper;		//operador: '+', '-', '*', '/'
	float val;		//valor do operando
	struct Exp *esq, *dir;
};

typedef struct Exp Exp;

Exp* Parse(char v[], int i);

#endif