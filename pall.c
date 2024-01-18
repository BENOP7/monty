#include "monty.h"

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		return;

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
