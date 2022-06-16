#include "monty.h"

/**
 * push - push a node to the stack
 * @stack: the stack
 * @val: value to be pushed
 * Return: pointer to the new node on SUCCESS otherwise returns NULL
 */
void push(stack_t **stack, int val)
{
	stack_t *res = add_stackint(stack, val);

	if (res == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
