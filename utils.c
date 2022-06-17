#include "monty.h"
#include <string.h>
#include <ctype.h>



void interprete(char **list, unsigned int line_no)
{
	instruction_t instructions[] = {{"pall", print_stackint},
			{"pint", pint}};
	unsigned int i = 0;

	if (strcmp(*list, "push") == 0)
	{
		if (strlen(list[1]) == 0 || isnumber(list[1]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_no);
			exit(EXIT_FAILURE);
		}
		else
		{
			push(&head, atoi(list[1]));
			return;
		}
	}
	for (; i < 2; i++)
	{
		if (strcmp(instructions[i].opcode, *list) == 0)
		{
			instructions[i].f(&head, line_no);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, *list);
	exit(EXIT_FAILURE);
}

int isnumber(char *s)
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
