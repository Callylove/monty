#include "monty.h"

/**
 * _get_handler - checks for a registered handler for a given opcode
 * @opcode: the opcode to get handler for
 *
 * Return: the handler found. if no valid handler exists,
 * a default NULL-based handler is returned
 */
instruction_t _get_handler(const char *opcode)
{
	int i;
	static instruction_t handlers[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pchar", pchr_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"pop", pop_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"swap", swap_handler},
		{"sub", sub_handler},
		{"mul", mul_handler},
		{"pint", pint_handler},
		{"div", div_handler},
		{"mod", mod_handler},
		{NULL, NULL}
	};

	for (i = 0; handlers[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, handlers[i].opcode) == 0)
			break;
	}
	return (handlers[i]);
}
