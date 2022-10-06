#include "monty.h"

/**
 * push_handler - handles push operation
 * @s: pointer to stack
 * @l: line number
 */
void push_handler(stack_t **s, unsigned int l)
{
	int n;
	(void)s;
	(void)l;

	if (!global.arg || !is_number(global.arg))
	{
		/* error */
		fprintf(stderr, "L%u: usage: push integer\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	n = atoi(global.arg);
	if (global.mode == STACK)
		push(n);
	else
		enqueue(n);
}


/**
 * pop_handler - handles pop operation
 * @s: pointer to stack
 * @l: line number
 */
void pop_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;

	if (!global.head)
	{
		/* error underflow */
		dprintf(2, "L%u: can't pop an empty stack\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	if (global.mode == STACK)
		pop();
	else
		dequeue();
}

/**
 * swap_handler - handles swap operation
 * @s: pointer to stack
 * @l: line number
 */
void swap_handler(stack_t **s, unsigned int l)
{
	(void)s;
	if (!global.head || !global.head->next)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	swap();
}

/**
 * pall_handler - handles pall operation
 * @s: pointer to stack
 * @l: line number
 */
void pall_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;

	if (global.mode == QUEUE)
		print_queue();
	else
		print_stack();
}

/**
 * nop_handler - handles nop operation
 * @s: pointer to stack
 * @l: line number
 */
void nop_handler(stack_t **s, unsigned int l)
{
	(void)s;
	(void)l;
}
