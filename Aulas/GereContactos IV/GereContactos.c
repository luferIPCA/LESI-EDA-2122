/**
*  @file GereContactos.c
 * @author lufer
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada Simples de Contactos
 * @bug No known bugs.
*/
#include "Contatos.h"
#include "Pessoa.h"

#include "GruposABP.h"

#include  <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//Gere Lista de Contactos
	Contacto* c1 = CriaContacto("Telef", "253123321");
	ListaContactos* contactos = NULL;
	contactos = InsereContactoListaContactos(contactos, c1);
	MostraContactos(contactos);

	//Gere Lista de Pessoas
	ListaPessoa* inicio = NULL;
	Pessoa* p = CriaPessoa("PP", 12345);
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

	//Preserva todas as pessoas em arquivo
	SavePessoas(inicio, "Pessoas.dat");
	//Preserva todos os contactos em arquivo
	SaveAll(inicio, "All.dat");

	MostraTodasPessoas(inicio);

	inicio = NULL;	//ATENÇÃO: não é suficiente NULL...deve destruir-se a lista
	//Carrega todas as pessoas em arquivo
	inicio = GetAllPessoas("Pessoas.dat");
	//Carrega todos os contatos em arquivo
	inicio = GetAll("All.dat", inicio);

	puts("\nApós Carregamento dos Ficheiros\n");
	MostraTodasPessoas(inicio);

	
	//Gere Grupos de Pessoas
	puts("\nGrupos de Pessoas\n");
	NodeTree *rootGrupos = CreateTree();
	GrupoPessoas *g = CriaGrupoPessoas(1, inicio);
	rootGrupos =AddNodeTree(rootGrupos, g);
	ShowNodeTree(rootGrupos);

	Contacto* c3 = CriaContacto("Email", "111@111.pt");
	rootGrupos = InsereContactoPessoaGrupo(rootGrupos, 1, 1, c3);
	ShowNodeTree(rootGrupos);
}