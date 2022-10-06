#include "monty.h"

/**
 * read_file - reads an entire content of a file
 * @path: path of the file
 * Return: pointer to content
 */
char *read_file(const char *path)
{
	FILE *f;
	long int fsize;
	char *string;

	f = fopen(path, "rb");
	if (!f)
	{
		dprintf(2, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	fseek(f, 0, SEEK_END);
	fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	string = malloc(fsize + 1);
	if (!string)
	{
		/* handle memory */
		fclose(f);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fread(string, fsize, 1, f);
	fclose(f);
	string[fsize] = 0;
	return (string);
}
