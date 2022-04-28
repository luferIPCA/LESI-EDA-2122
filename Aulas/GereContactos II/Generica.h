/*****************************************************************//**
 * @file   Generica.h
 * @brief  Módulo genérico de Listas Ligadas
 * 
 * @author lufer
 * @date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>

#pragma region Genericas

typedef struct ListElem {
	void* data;
	struct ListElem* next;
}ListElem;

/**
 * @brief Insert a new element with *data in the head of the list 
 *	*data must point to storage in the heap.
 */
ListElem* addItemHead(ListElem* head, void* data);
ListElem* CriaListaHistorico();
void Show(ListElem* head, void (*show)(void* data));

#pragma endregion


