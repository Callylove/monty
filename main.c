#include "monty.h"

/* Initialise Global variables */
global_t global = {
	NULL, NULL, STACK, 0, NULL
};

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	char *content;
	char **lines;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	content = read_file(argv[1]);
	/* truncate_on_empty_line(content); */
	lines = strtow(content, "\n");
	free(content);
	if (!lines)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	parse_instructions(lines);

	free_tokenized(lines);
	clear_memory();
	if (global.quit == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	return (0);
}
