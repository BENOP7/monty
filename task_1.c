#include "monty.h"

/**
 * pint - print element at the top of the stack
 * @stack: stack
 * @line_no: line number
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
}
