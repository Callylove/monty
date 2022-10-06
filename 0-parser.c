#include "monty.h"

/**
 * parse_instructions - parse the instructions
 * Description:
 * Uses the line in the moty file
 * and executes the instructions
 * @lines: lines read from the file
 */

void parse_instructions(char **lines)
{
	char **args;
	instruction_t cmd;
	unsigned int line;

	for (line = 0; lines[line]; line++)
	{
		args = strtow(lines[line], DELIM);
		if (!args || !args[0])
			continue;
		if (simple_opcodes(args))
			continue;
		if (args[0][0] == '#')
		{
			free_tokenized(args);
			continue;
		}
		cmd = _get_handler(args[0]);
		if (!cmd.f)
		{
			/* handle invalid command */
			dprintf(2, "L%u: unknown instruction %s\n", line + 1, args[0]);
			free_tokenized(args);
			global.quit = EXIT_FAILURE;
			break;
		}
		global.arg = args[1];
		cmd.f(&global.head, line + 1);
		free_tokenized(args);
		if (global.quit == EXIT_FAILURE)
			break;
	}

}

/**
 * simple_opcodes - handle simple opcodes
 * @args: the args
 * Return: 1 if found 0 otherwise
 */
int simple_opcodes(char **args)
{
	char *opcode = args[0];
	int result = 1;

	if (strcmp(opcode, "queue") == 0)
		global.mode = QUEUE;
	else if (strcmp(opcode, "stack") == 0)
		global.mode = STACK;
	else
		result = 0;
	if (result)
		free_tokenized(args);
	return (result);
}

/**
 * process_args - chexk for validity of arg
 * @args: arguments array
 */
void process_args(char **args)
{
	int count = arrlen(args);

	if (!count)
		global.arg = NULL;
	else if (count == 1)
		global.arg = args[0];
	else
	{

	}
}
