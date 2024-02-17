#include "monty.h"
mine_t mine = {NULL, NULL, NULL, NULL, 0};

/**
 * main - main function
 * @argc: argument number
 * @argv: number of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char value[1032];
	FILE *file;
	char *read;
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
	while ((read = fgets(value, sizeof(value), file)) != NULL)
	{
		mine.value = value;
		count++;
		execute(value, &stack, count, file);
	}
	freestack(stack);
	fclose(file);
	return (0);
}
