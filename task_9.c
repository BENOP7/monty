#include "monty.h"

/**
 * modo - modulo top two elements of stack
 * @stack: stack
 * @line_no:
 *
 */
void modo(stack_t **stack, unsigned int line_no)
{
	stack_t *low_elt = NULL; 
	
	if (stack_len(*stack) > 1)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_no);
			exit(EXIT_FAILURE);
		}
		low_elt = (*stack)->next;
		low_elt->n = low_elt->n % (*stack)->n;
		free(*stack);
		*stack = low_elt;

	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
}
