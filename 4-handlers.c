#include "monty.h"

/**
 * pint_handler - handles pint operation
 * @s: pointer to stack
 * @l: line number
 */
void pint_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (!global.head)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	printf("%d\n", global.head->n);
}

/**
 * temp_handler - handles mode change
 * @s: pointer to stack
 * @l: line number
 */
void temp_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;
}

/**
 * pchr_handler - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pchr_handler(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		global.quit = EXIT_FAILURE;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		global.quit = EXIT_FAILURE;
		return;
	}
	printf("%c\n", (*stack)->n);
}
