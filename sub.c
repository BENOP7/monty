#include "monty.h"

/**
 * sub - subtracts top two elements of stack
 * @stack: stack
 * @line_no: line number
 *
 */
void sub(stack_t **stack, unsigned int line_no)
{
	stack_t *low_elt = NULL;
	*stack = global->head;

	if (global->head && global->head->next)
	{
		low_elt = (global->head)->next;
		low_elt->n = low_elt->n - (global->head)->n;
		free(global->head);
		global->head = low_elt;

	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
