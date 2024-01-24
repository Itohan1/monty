#include "monty.h"

/**
 * execute - executes operations
 * @value: content of file
 * @stack: head of stack
 * @count: counter
 * @file: file
 * Return: 1
 */

int execute(char *value, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t son[] = {{"push", fpush}, {"pall", fpall}, {NULL, NULL}};

	unsigned int i = 0;

	char *op;

	op = strtok(value, " \n\t");
	if (op && op[0] == '#')
		return (0);
	mine.arg = strtok(NULL, " \n\t");
	while (son[i].opcode && op)
	{
		if (strcmp(op, son[i].opcode) == 0)
		{
			son[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && son[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown %s\n", count, op);
		fclose(file);
		free(value);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
