#include "monty.h"
#include "globe.h"

/**
 * main - This is where the monty program starts
 * @ac: number of arguments to the main function
 * @av: argument list
 *
 * Return: EXIT_SUCCESS on completion, otherwise returns EXIT_FAILURE
 */
int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line = NULL;
	char *line_ptr = NULL;
	char **tokens = NULL;
	char *tok;
	int i = 0;
	int lno = 0;
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
	allocate_memory(&line, &tokens);
	line_ptr = line;
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

/**
 * allocate_memory - allocates buffer to for each line and list of tokens
 * @line: pointer to the line buffer
 * @token_list: list of tokens on a single line
 *
 */
void allocate_memory(char **line, char ***token_list)
{
	const int line_size = 1024;

	*line = malloc(sizeof(**line) * line_size);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*token_list = malloc(sizeof(**token_list) * 55);
	if (token_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

}
