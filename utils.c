#include "monty.h"


/**
 * isnum - checks if the content of a string can be converted to a number
 * @s: string
 *
 * Return: 1 if string is a valid number, 0 otherwise
 */
int isnum(char *s)
{
	unsigned int i = 0;

	if (s == NULL || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (!isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}
/**
 * len - len of list of operands
 * @list: list of operands
 *
 * Return: size of list
 */
int len(char **list)
{
	int size = 0;

	while (list[size])
	{
		size++;
	}
	return (size);
}

/**
 * interprete - executes the line containing the monty instruction
 * @line_toks: null-terminated list of line tokens
 * @line_no: line number of line being executed
 *
 * Return: 0 on success, 1 if any error occurs
 */
int interprete(char **line_toks, unsigned int line_no)
{
	instruction_t instructions[] = {{"pall", pall}, {"pint", pint}, {"nop", nop},
					{"pop", pop}, {"swap", swap}, {"add", add}};
	unsigned int i;

	if (line_toks == NULL)
	{
		return (EXIT_FAILURE);
	}


	if (strcmp(*line_toks, "push") == 0)
	{
		if (len(line_toks) < 2 || !isnum(line_toks[1]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_no);
			return (EXIT_FAILURE);
		}
		push(atoi(line_toks[1]));
		return (EXIT_SUCCESS);
	}
	for (i = 0; i < (sizeof(instructions) / sizeof(*instructions)); i++)
	{
		if (strcmp(instructions[i].opcode, line_toks[0]) == 0)
		{
			instructions[i].f(&(global->head), line_no);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

/**
 * free_stack - free the stack
 */

void free_stack(void)
{
	stack_t *curr = global->head;
	stack_t *tmp = NULL;

	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}
