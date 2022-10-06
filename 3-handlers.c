#include "monty.h"

/**
 * add_handler - handles add operation
 * @s: pointer to stack
 * @l: line number
 */
void add_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('+', "add", l);
}

/**
 * sub_handler - handles sub operation
 * @s: pointer to stack
 * @l: line number
 */
void sub_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('-', "sub", l);
}

/**
 * mul_handler - handles mul operation
 * @s: pointer to stack
 * @l: line number
 */
void mul_handler(stack_t **s, unsigned int l)
{
	(void)s;

	calculator('*', "mul", l);
}

/**
 * div_handler - handles div operation
 * @s: pointer to stack
 * @l: line number
 */
void div_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (global.head && !global.head->n)
	{
		dprintf(2, "L%u: division by zero\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	calculator('/', "div", l);
}

/**
 * mod_handler - handles mod operation
 * @s: pointer to stack
 * @l: line number
 */
void mod_handler(stack_t **s, unsigned int l)
{
	(void)s;

	if (global.head && !global.head->n)
	{
		dprintf(2, "L%u: division by zero\n", l);
		global.quit = EXIT_FAILURE;
		return;
	}
	calculator('%', "mod", l);
}
