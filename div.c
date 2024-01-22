#include "monty.h"

/**
 * divide - divides top two elements of stack
 * @stack: stack
 * @line_no: line number
 *
 */
void divide(stack_t **stack, unsigned int line_no)
{
	stack_t *low_elt = NULL;
	*stack = global->head;

	if (global->head && global->head->next)
	{
		if (global->head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_no);
			free_memory();
			exit(EXIT_FAILURE);
		}
		low_elt = (global->head)->next;
		low_elt->n = low_elt->n / (global->head)->n;
		free(global->head);
		global->head = low_elt;

	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
