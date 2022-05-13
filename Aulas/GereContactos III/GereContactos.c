/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief	Lista Ligadas Simples (versão 1)
 *			Resolução Folha de Exercícios 4.3
 * Metodos para manipular uma Árvores Binárias de Histórico
 * @bug No known bugs.
*/
#include "Contatos.h"
#include "Pessoa.h"
#include "GenericaABP.h"
#include  <locale.h>

#pragma region GereInteiros
//Métodos para demmonstrar árvore genérica aplicada a inteiros

int CompInt(int *x, int *y) {
	return (*x - *y);
}

void PrintInt(int* x) {
	printf("%d\n", *x);
}

#pragma endregion

int main() {
	setlocale(LC_ALL, "Portuguese");

#pragma region ArvoreGenericaInteiros

	//Exemplo Árvore genérica para conter inteiros
	Node* rootTemp = NULL;
	int x = 12;
	int y = 13;
	rootTemp = AddNode(rootTemp, &x, CompInt);
	rootTemp = AddNode(rootTemp, &y, CompInt);
	ShowTree(rootTemp, PrintInt);

#pragma endregion

#pragma region Lista_e_Arvore_Pessoas_Contactos

	//Inicia árvore
	Node* historico = InitTree();

	Contacto* c1 = CriaContacto("Telef", "253123321");
	ListaContactos* contactos = NULL;
	contactos = InsereContactoListaContactos(contactos, c1);
	MostraContactos(contactos);

	Pessoa* p = CriaPessoa("PP", 12345);
	ListaPessoa* inicio = NULL;
	inicio = InserePessoaListaPessoas(inicio, p);

	Pessoa* p2 = CriaPessoa("JJ", 4321);
	inicio = InserePessoaListaPessoas(inicio, p2);
	MostraTodasPessoas(inicio);

	inicio = InsereContactoPessoa(inicio, c1, 12345);

	p = CriaPessoa("CC", 1);
	inicio = InserePessoaListaPessoas(inicio, p);

	p = CriaPessoa("DD", 13345);
	inicio = InserePessoaListaPessoas(inicio, p);

	Contacto* c2 = CriaContacto("Email", "aaa@bbb.pt");
	inicio = InsereContactoPessoa(inicio, c2, 4321);

	MostraContactosPessoa(inicio, 12345);
	MostraContactosPessoa(inicio, 4321);

	SavePessoas(inicio, "Pessoas.dat");
	SaveAll(inicio, "All.dat");

	MostraTodasPessoas(inicio);

	inicio = NULL;	//ATENÇÃO: não é suficiente NULL...deve destruir-se a lista
	inicio = GetAllPessoas("Pessoas.dat");
	inicio = GetAll("All.dat", inicio);

	puts("\nApós Ficheiro\n");
	MostraTodasPessoas(inicio);

	//Gere Historico
	inicio = RemovePessoaABP(inicio, 12345, &historico);
	puts("\nApós Remoção (I)\n");
	MostraTodasPessoas(inicio);

	puts("\nHistórico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa
	inicio = RemovePessoaABP(inicio, 1, &historico);
	puts("\nApós Remoção (II)\n");
	MostraTodasPessoas(inicio);
	puts("\nHistórico\n");
	ShowTree(historico, ShowPessoa);	//mesmo que &ShowPessoa
	
	//Preservar e Carregar Árvore
	bool aux = GuardaHistorico(historico, "tree.dat");
	Node* historico2 = InitTree();
	historico2 = GetHistorico("tree.dat");
	ShowTree(historico2, ShowPessoa);

#pragma endregion
}