#include "monty.h"
#include "globe.h"


/**
 * file_open - checks if a file is provided on command line and opens the file
 * @file: monty bytecode file
 * @ac: size of argument list
 * @av: list of arguments from the command line
 *
 */
void file_open(FILE **file, int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	*file = fopen(av[1], "r");
	if (*file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * file_close - frees all allocated memory and closes the input file stream
 * @file: monty bytecode file
 * @line: line buffer
 * @tokens: token buffer
 *
 */
void file_close(FILE *file, char *line, char **tokens)
{
	free(tokens);
	free(line);
	free_stack();
	fclose(file);
}

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
	int error = 0;
	int i = 0;
	int lno = 0;
	size_t line_size = 1024;

	file_open(&file, ac, av);
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
		if ((error = interprete(tokens, ++lno)))
			break;
		memset(line, 0, line_size);
	}
	file_close(file, line_ptr, tokens);
	if (error)
		return (EXIT_FAILURE);
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
