#include "monty.h"

/**
 * rotr_handler - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	top = (*stack);
	bottom = (*stack);
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack) = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}


/**
 * rotl_handler - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	top = (*stack);
	bottom = (*stack);
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack) = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * pstr_handler - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack);

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		if (tmp->n > 127 || tmp->n < 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
