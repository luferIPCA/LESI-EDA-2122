/*
Manipular Tabelas de Hash
lufer
2022
*/

#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "hash.h"

int main() 
{	
	setlocale(LC_ALL, "Portuguese");

	printf("Hash(Maria)=%d\n", Hash("Maria"));
	printf("Hash(Maria João)=%d\n", Hash("Mario"));


	// ===================== GERIR HASH ===================
	{
		//Iniciar Hash Table
		IniciaHash(hashTable,MAX);
		//ou
		//*hashTable = IniciaHashII(hashTable);

		*hashTable = InsertValHash("Luís Vaz de Camões", hashTable);
		
		NodePtr novo1 = NewNode("Fernando Pessoa");
		*hashTable = InsertNodeHash(novo1, hashTable);
		//ou
		//InsertNodeHashVoid(novo1, hashTable);	

		ShowHash(hashTable);

		NodePtr novo2 = NewNode("Eça de Queiroz");
		//*hashTable = InsertNodeHash(novo2, hashTable);
		InsertNodeHashVoid(novo2, hashTable);

		NodePtr novo3 = NewNode("Mário Zambujal");
		//*hashTable = InsertNodeHash(novo3, hashTable);
		InsertNodeHashVoid(novo3, hashTable);

		ShowHash(hashTable);

		NodePtr aux = FindNode("Mário Zambujal", hashTable);
		ShowNode(aux);


		NodePtr novo4 = NewNode("Agostinha Bessa Luís");
		*hashTable = InsertNodeHash(novo4, hashTable);

		NodePtr novo5 = NewNode("José Saramago");
		*hashTable = InsertNodeHash(novo5, hashTable);
		novo5 = NewNode("José Saramago");
		InsertNodeHashVoid(novo5, hashTable);
		/*
		InsertNodeHashVoid(novo5, hashTable);
		InsertNodeHashVoid(novo5, hashTable);
		*/
		ShowHash(hashTable);


		*hashTable = Cleanup(hashTable);
		ShowHash(hashTable);
	}
}