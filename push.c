#include "monty.h"

void push(__attribute__((unused)) char **list, const int n)
{
	stack_t *top = NULL;

	top = malloc(sizeof(*top));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack_head == NULL)
	{
		top->n = n;
		top->prev = NULL;
		top->next = NULL;
		stack_head = top;
		return;
	}
	(stack_head)->prev = top;
	top->next = stack_head;
	top->prev = NULL;
	top->n = n;
	stack_head = top;
}
