#include "monty.h"

/**
 * swap - swaps the first two elements
 */
void swap(void)
{
	stack_t *temp;

	temp = global.head->next;
	global.head->next = temp->next;
	temp->next = global.head;
	global.head->prev = temp;
	temp->prev = NULL;
	global.head = temp;
}
