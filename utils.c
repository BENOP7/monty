#include "monty.h"

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
		if (isdigit(s[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}

int len(char **list)
{
	int size = 0;

	while (list[size])
	{
		size++;
	}
	return (size);
}

void interprete(char **line_toks, unsigned int line_no)
{
	instruction_t instructions[] = {{"pall", pall}};
	unsigned int i;

	if (line_toks == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (strcmp(*line_toks, "push") == 0)
	{
		if (len(line_toks) < 2 || !isnum(line_toks[1]))
		{
			return;
		}
		push(line_toks, atoi(line_toks[1]));
		return;
	}
	for (i = 0; i < (sizeof(instructions) / sizeof(*instructions)); i++)
	{
		if (strcmp(instructions[i].opcode, line_toks[0]) == 0)
		{
			instructions[i].f(&stack_head, line_no);
			return;
		}
	}
}

void free_stack()
{
	stack_t *curr = stack_head;
	stack_t *tmp = NULL;

	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}
