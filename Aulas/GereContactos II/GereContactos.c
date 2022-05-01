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
#include "Generica.h"
#include  <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	ListElem* historico = CriaListaHistorico();

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

	MostraTodasPessoas(inicio);

	//Gere Historico
	inicio = RemovePessoa(inicio, 12345, &historico);
	puts("\nApós Remoção\n");
	MostraTodasPessoas(inicio);
	puts("\nHistórico\n");
	Show(historico, ShowPessoa);

}