/*****************************************************************//**
 * @file   Historico.c
 * @brief  Registo das pessoas que foram removidas
 *		   Usa Módulo Genérico de Listas Ligadas
 * 
 * @author lufer
 * @date   April 2022
 *********************************************************************/

#include "Generica.h"

/**
 * @brief .
 * 
 * @param head
 * @param data
 * @return 
 */
ListElem* addItemHead(ListElem* head, void* data) {

	if (data==NULL) return head;
	ListElem* aux;
	if (head == NULL) {
		aux = (ListElem*)malloc(sizeof(ListElem));
		aux->data = data;
		aux->next = NULL;
		head = aux;
		return head;
	}
	head->next = addItemHead(head->next, data);
	return head;
}

ListElem* CriaListaHistorico() {
	return NULL;
}

void Show(ListElem* head, void (*show)(void* data)) {
	while (head != NULL) {
		show(head->data);
		head = head->next;
	}
}
