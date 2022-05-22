
#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "btree.h"

int main() {

	setlocale(LC_ALL, "Portuguese");

	PtrNode raiz = InitTree();		//raiz=NULL;
	//printf("%d", raiz == NULL);

	Element e;

	e.val = 12;
	raiz = AddNode(raiz, e);

	e.val = 7;
	raiz = AddNode(raiz, e);

	e.val = 15;
	raiz = AddNode(raiz, e);

	PreOrder(raiz);

	DeleteNode(raiz, e);
	//DestroyNode(&raiz);

	printf("-------------------\n");
	PreOrder(raiz);

	e.val = 15;
	raiz = AddNode(raiz, e);

	e.val = 9;
	raiz = AddNode(raiz, e);

	e.val = 8;
	raiz = AddNode(raiz, e);

	e.val = 6;
	raiz = AddNode(raiz, e);

	PreOrder(raiz);

	printf("-------------------\n");

	//e.val = 7;
	//DeleteNode(raiz, e);

	PreOrder(raiz);

	printf("-------------------\n");

	/*Node *listNode;
	unsigned int tot = TreeSize(raiz);
	unsigned int count = 0;*/

	//listNode = (Node *)malloc(sizeof(Node)*tot);
	//BTS2List(raiz, &count, listNode);

	Show(raiz,1);

	raiz = Balance(raiz);

	Show(raiz, 1);

	system("pause");
	return 0;
}