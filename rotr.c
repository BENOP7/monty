#include "monty.h"

/**
 * rotr - opcode; rotates stack to the bottom
 * @stack: pointer to stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	*stack = tmp;

}
