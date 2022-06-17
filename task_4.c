#include "monty.h"

/**
 * add - add top two elements of stack
 * @stack: stack
 * @line_no:
 *
 */
void add(stack_t **stack, unsigned int line_no)
{
	stack_t *low_elt = NULL; 
	
	if (stack_len(*stack) > 1)
	{
		low_elt = (*stack)->next;
		low_elt->n = (*stack)->n + low_elt->n;
		free(*stack);
		*stack = low_elt;

	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
}
