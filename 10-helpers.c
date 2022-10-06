#include "monty.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if is lower 0 otherwise;
 */

int _isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

/**
 * is_number - check if a string is number
 * @str: string pointer
 * Return: 0 if false 1 if true
 */

int is_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * _strcmp - compares src with dst
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: -ve if dst < src
 * +ve if dst > src
 * 0 if src == dst
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0, diff = 0;

	while (diff == 0)
	{
		diff = s1[x] - s2[x];
		if (s1[x] == '\0' || s2[x] == '\0')
			break;
		x++;
	}
	return (diff);
}

/**
 * arrlen - length of array
 * @args: array
 * Return: the length
 */

int arrlen(char **args)
{
	int i = 0;

	while (args[i])
		i++;
	return (i);
}
