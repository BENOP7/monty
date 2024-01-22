#include "monty.h"


/**
 * pchar - prints the character at top of stack
 * @stack: stack
 * @line_no: line number
 *
 */
void pchar(stack_t **stack, unsigned int line_no)
{
	*stack = global->head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		free_memory();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n < 128)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		free_memory();
		exit(EXIT_FAILURE);
	}
}
