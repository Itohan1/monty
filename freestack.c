#include "monty.h"

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
