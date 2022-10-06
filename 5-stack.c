#include "monty.h"

/**
 * push - push an element into stack
 * @n: data to push
 */
void push(int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		/* handle overflow */
		fprintf(stderr, "Error: malloc failed\n");
		global.quit = EXIT_FAILURE;
		return;
	}
	new->n = n;
	new->next = global.head;
	if (!global.head)
		global.tail = new;
	else
		global.head->prev = new;
	global.head = new;
}

/**
 * pop - pops an element from the stack
 * Return: the value removed
 */

int pop(void)
{
	int res;
	stack_t *temp = global.head;

	res = global.head->n;
	if (global.head != global.tail)
		global.head->next->prev = 0;
	else
		global.tail = 0;
	global.head = global.head->next;
	free(temp);
	return (res);
}

/**
 * print_stack - prints a stack in LIFO
 */

void print_stack(void)
{
	stack_t *temp = global.head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

