#include "monty.h"

/**
 * fpush - pushes an element to the stack
 * @stack: stack value
 * @line_number: line number
 * Return: void
 */

void fpush(stack_t **stack, unsigned int line_number)
{
	int n, q = 0, flag = 0;

	if (mine.arg)
	{
		if (mine.arg[0] == '-')
			q++;
		for (; mine.arg[q] != '\0' ; q++)
		{
			if (mine.arg[q] > 57 || mine.arg[q] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(mine.file);
			free(mine.value);
			freestack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(mine.file);
		free(mine.value);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(mine.arg);
	if (mine.LIFI == 0)
		addn(stack, n);
	else
		addq(stack, n);
}
