
/*****************************************************************//**
 * @file   GruposABP.c
 * @brief  Gestão de Grupos de Pessoas com uma ABP
 * 
 * @author lufer
 * @date   May 2022
 *********************************************************************/
#include "Pessoa.h"

/**
 * Nodo de Grupo de Pessoas.
 */
typedef struct GrupoPessoas {
	int codGrupo;
	ListaPessoa* pessoas;
}GrupoPessoas;


/**
 * Nodo da Árvore.
 */
typedef struct NodeTree {
	GrupoPessoas *element;
	struct NodeTree* leftNode;
	struct NodeTree* rightNode;
}NodeTree;


//Gerir a Árvore
NodeTree *CreateTree();
NodeTree *NewNodeTree(GrupoPessoas *g);
NodeTree *AddNodeTree(NodeTree *root, GrupoPessoas *g);
void ShowNodeTree(NodeTree *root);
NodeTree* SearchNodeTree(NodeTree* r, int codG);

//Gerir Contactos nas Pessoas dos Grupos
NodeTree* InsereContactoPessoaGrupo(NodeTree* r, int codGrupo, int codPessoa, Contacto* c);
GrupoPessoas* CriaGrupoPessoas(int cod, ListaPessoa* h);