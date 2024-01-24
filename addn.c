#include "monty.h"

/**
 * addn - adds a node
 * @head: stack head
 * @n: number
 * Return: void
 */

void addn(stack_t **head, int n)
{
	stack_t *node, *tem;

	tem = *head;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (tem)
	{
		tem->prev = node;
		node->n = n;
		node->next = *head;
		node->prev = NULL;
		*head = node;
	}
}

