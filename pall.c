#include "monty.h"

void pall(stact_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
