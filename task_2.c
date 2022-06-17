#include "monty.h"

/**
 * pop - pop element from top of the stack
 * @stack: stack
 * @line_no: line number
 */
void pop(stack_t **stack, unsigned int line_no)
{
	if (*stack)
		delete_stackint_at_index(&head, 0);
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
}

/**
 * delete_stackint_at_index - deletes a node at a given position in a doubly
 * linked list
 * @head: pointer to the first node of the list
 * @index: position of node to be deleted
 * Return: 1 on SUCCESS, -1 on FAILURE
 */
int delete_stackint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	tmp = *head;
	do {
		if (count == index)
		{
			*head = tmp->next;
			free(tmp);
			if (*head)
				(*head)->prev = NULL;
			return (1);
		}
		++count;
		tmp = tmp->next;
	} while (tmp == NULL);
	return (-1);
}
