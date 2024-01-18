#include "monty.h"
#include <string.h>

stack_t *stack_head = NULL;

int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line = NULL;
	char *line_ptr = NULL;
	char **tokens = NULL;
	char *tok;
	int i = 0;
	__attribute__((unused)) int lno = 0;
	size_t line_size = 1024;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}

	line = malloc(sizeof(*line) * line_size);
	if (line == NULL)
	{
		return (EXIT_FAILURE);
	}
	line_ptr = line;
	tokens = malloc(sizeof(*tokens) * 55);
	if (tokens == NULL)
	{
		return (EXIT_FAILURE);
	}

	while ((line = fgets(line, line_size, file)))
	{
		tok = strtok(line, " \n");
		while (tok)
		{
			tokens[i++] = tok;
			tok = strtok(NULL, " \n");
		}
		tokens[i] = NULL;
		i = 0;
		interprete(tokens, lno++);
		memset(line, 0, line_size);
	}
	free(tokens);
	free(line_ptr);
	free_stack();
	fclose(file);
	return (EXIT_SUCCESS);
}
