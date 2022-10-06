#include "monty.h"

/**
 * clear_memory - clears memory
 */
void clear_memory(void)
{
	stack_t *temp;

	/* Clear Data structure */
	while (global.head)
	{
		temp = global.head->next;
		free(global.head);
		global.head = temp;
	}
}

/**
 * free_tokenized - frees an array of array
 * @tokens: the array to free
 */
void free_tokenized(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
