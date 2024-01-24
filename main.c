#include "monty.h"

char *value[113];

/**
 * main - main function
 * @argc: argument number
 * @argv: number of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *value;
	FILE *file;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	mine.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: can't open file\n");
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		value = NULL;
		if (fgets(value, sizeof(value), stdin) != NULL)
		{
			printf("%s\n", value);
		}
		else
		{
			printf("Error\n");
		}
		mine.value = value;
		count++;
		if (read > 0)
		{
			execute(value, &stack, count, file);
		}
		free(value);
	}
	freestack(stack);
	fclose(file);
	return (0);
}
