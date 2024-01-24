#include "monty.h"

/**
 * addq - add node to end of stack
 * @head: stavk head
 * @n: number
 * Return: void
 */

void addq(stack_t **head, int n)
{
	stack_t *node, *tem;

	tem = *head;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
	}
	node->n = n;
	node->next = NULL;
	if (tem)
	{
		while (tem->next)
			tem = tem->next;
	}
	if (!tem)
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		tem->next = node;
		node->prev = tem;
	}
}
