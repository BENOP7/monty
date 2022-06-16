#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

/**
 * add_stackint - add node at the beginning of a linked list
 * @head: first node
 * @n: number to assign to the new node
 * Return: pointer to the new node
 */
stack_t *add_stackint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}

/**
 * print_stackint - print all the elements of a doubly linked list
 * @h: pointer to the linked list
 * @line_no: line number
 * Return: number of nodes of the linked list
 */
void print_stackint(stack_t **h, unsigned int line_no __attribute__((unused)))
{
	stack_t *current;
	size_t count = 0;

	if (!*h)
		return;
	current = *h;
	do {
		printf("%d\n", current->n);
		++count;
		current = current->next;
	} while (current);
}
