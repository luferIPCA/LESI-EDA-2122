/*
Hash Table: 
	Index->Lista Ligada
lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include "Listas.h"



#ifndef HASH
#define HASH
#define MAX 31 /* tamanho da tabela de hashing -> recomenda-se que seja primo */

//h1: Tabela de Hash
typedef struct HashTable {
	int max;
	struct Node** tabela;
	//ou
	//struct Node* tabela[MAX];
}HashTable;



//h2: Tabela de Hash
static struct Node* hashTable[MAX];	

//char* nome;
//char nome1[20];

//char** nome2;
//char nome2[][];


//Assinaturas de Métodos
//Funções de Hash
int Hash(char* palavra);
int HashII(int val);

//Manipular Hash
void IniciaHash(Node *ht[], int n);
Node **IniciaHashII(Node *ht[]);
Node ** InsertValHash(char* autor, Node *ht[]);
Node ** InsertNodeHash(Node *autor, Node *ht[]);
Node ** InsertNodeHashInicio(Node* item, Node *ht[]);

void ShowHash(Node *ht[]);
NodePtr FindNode(char *val, Node *ht[]);
Node **Cleanup(Node *ht[]);

void InsertNodeHashVoid(Node* item, Node **ht);
bool InsertNodeHashBool(Node* item, Node **ht);
bool InsertNodeHashInicioII(Node* item, Node *ht[]);

//Auxiliares
void AsciiTable();
int ToUpperCase(char c);

//Preservar Hash em Ficheiro
bool SaveHash(Node** h, char* fileName);
Node** GetHash(char* fileName);


#endif // !HASH

