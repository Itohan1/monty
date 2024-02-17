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
	size_t c = 0;


	char *op, *ops[2];

	op = strtok(value, " \n\t");
	while (op != NULL)
	{
		ops[c++] = op;
		op = strtok(NULL, " \n\t");
	}
	mine.arg = ops[0];
	mine.arg2 = ops[1];
	while (son[i].opcode && ops[0])
	{
		if (strcmp(son[i].opcode, ops[0]) == 0)
		{
			son[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (ops[0] && son[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: ", i);
		fclose(file);
		free(value);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
