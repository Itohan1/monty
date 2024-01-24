#include "monty.h"

/**
 * fpall - prints all the values on the stack, starting from the top of the stack
 * @head: head of stack
 * @line_number: line number
 * Return: void
 */

void fpall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
