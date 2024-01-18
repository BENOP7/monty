#include "monty.h"

void push(char **list, const int n)
{
	stack_t *top = NULL;

	top = malloc(sizeof(*top));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (stack_head != NULL)
		(stack_head)->prev = top;
	top->next = stack_head;
	top->prev = NULL;
	top->n = n;
	stack_head = top;
}
