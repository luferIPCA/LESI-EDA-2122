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

int main() {

	ListaPessoa* inicio = NULL;
	inicio= GetData("Dados.txt");

	if (inicio == NULL) {//Se não existem dados de entrada, insere manualmente
		Contacto* c1 = CriaContacto("Telef", "253123321");
		ListaContactos* contactos = NULL;
		contactos = InsereContactoListaContactos(contactos, c1);
		//MostraContactos(contactos);

		Pessoa* p = CriaPessoa("PP", 12345);
		inicio = InserePessoaListaPessoas(inicio, p);

		Pessoa* p2 = CriaPessoa("JJ", 4321);
		inicio = InserePessoaListaPessoas(inicio, p2);
		inicio = InsereContactoPessoa(inicio, c1, 12345);

		Contacto* c2 = CriaContacto("Email", "aaa@bbb.pt");
		inicio = InsereContactoPessoa(inicio, c2, 4321);
	}


	MostraTodasPessoas(inicio);
	MostraContactosPessoa(inicio, 1);
	MostraContactosPessoa(inicio, 123);

	SavePessoas(inicio, "Pessoas.dat");
	SaveAll(inicio, "All.dat");

	MostraTodasPessoas(inicio);

	inicio = NULL;	//ATENÇÃO: não é suficiente NULL...deve destruir-se a lista
	inicio = GetAllPessoas("Pessoas.dat");
	inicio = GetAll("All.dat", inicio);



	MostraTodasPessoas(inicio);
	MostraContactosPessoa(inicio, 123);
}