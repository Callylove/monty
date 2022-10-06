#include "monty.h"

/**
 * calculator - performs basic operation
 * Description:
 * performs one of +, -, *, / and %
 * with the top two elements
 *
 * @op: operation symbol
 * @opname: operation name
 * @line: line number
 */
void calculator(char op, char *opname,  int line)
{
	int res, a, b;

	if (!global.head || !global.head->next)
	{
		dprintf(2, "L%u: can't %s, stack too short\n", line, opname);
		global.quit = EXIT_FAILURE;
		return;
	}
	a = global.head->n;
	b = global.head->next->n;
	switch (op)
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = b - a;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = b / a;
		break;
	case '%':
		res = b % a;
		break;
	default:
		break;
	}
	global.head->next->n = res, pop();
}
