#include "monty.h"

void push(stack_t **stack, unsigned int line_number, const int n)
{
	stack_t *top = NULL;

	top = malloc(sizeof(*top));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->next = (*stack);
	top->prev = NULL;
	(*stack)->prev = top;
	top->n = n;
}
