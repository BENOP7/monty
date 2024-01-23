/**
 * pstr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		if (!isascii((tmp)->n))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
