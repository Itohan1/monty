#include "monty.h"

/**
 * fpush - pushes an element to the stack
 * @stack: stack value
 * @line_number: line number
 * Return: void
 */

void fpush(stack_t **stack, unsigned int line_number)
{
	int n = 0, q = 0;

	if (mine.arg)
	{
		if (mine.arg2[0] == '-')
			q++;
		for (; mine.arg2[q] != '\0' ; q++)
		{
			if (mine.arg2[q] > 57 || mine.arg2[q] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(mine.file);
				free(mine.value);
				freestack(*stack);
				exit(EXIT_FAILURE);
			}
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
	n = atoi(mine.arg2);
	if (mine.LIFI == 0)
		addn(stack, n);
	else
		addq(stack, n);
}
