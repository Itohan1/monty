#include "monty.h"

/**
 * freestack - free sstack function
 * @head: parameter
 * Return: 0
 */

void freestack(stack_t *head)
{
	stack_t *tem;

	tem = head;

	while (head)
	{
		tem = head->next;
		free(head);
		head = tem;
	}
}
