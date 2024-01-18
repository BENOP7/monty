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

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
