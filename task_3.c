#include "monty.h"

/**
 * swap - swap top two elements of stack
 * @stack: stack
 * @line_no:
 *
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *low_elt = NULL;
	
	if (stack_len(*stack) > 1)
	{
		low_elt = (*stack)->next;
		(*stack)->next = low_elt->next;
		low_elt->next = *stack;
		low_elt->prev = NULL;
		(*stack)->prev = low_elt;
		*stack = low_elt;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
}
