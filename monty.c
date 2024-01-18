#include "monty.h"
#include "globe.h"


/**
 * file_open - checks if a file is provided on command line and opens the file
 * @file: monty bytecode file
 * @ac: size of argument list
 * @av: list of arguments from the command line
 *
 */
void file_open(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global->file = fopen(av[1], "r");
	if (global->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_memory - frees all allocated memory and closes the input file stream
 * @line: line buffer
 * @tokens: token buffer
 *
 */
void free_memory(void)
{
	free(global->token_list);
	free(global->line);
	free_stack();
	fclose(global->file);
}

/**
 * create_global - allocate space for the globe structure
 *
 */
void create_global(void)
{
	globe_t *holder = malloc(sizeof(*holder));
	if (holder == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global = holder;
	global->head = NULL;
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
	char *line = NULL;
	char *tok;
	int error = 0;
	int i = 0;
	int lno = 0;
	size_t line_size = 1024;

	create_global();
	file_open(ac, av);
	allocate_memory();
	line = global->line;
	while ((line = fgets(line, line_size, global->file)))
	{
		tok = strtok(line, " \n");
		while (tok)
		{
			global->token_list[i++] = tok;
			tok = strtok(NULL, " \n");
		}
		global->token_list[i] = NULL;
		i = 0;
		global->line_no = ++lno;
		if ((error = interprete(global->token_list, global->line_no)))
			break;
		memset(line, 0, line_size);
	}
	free_memory();
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * allocate_memory - allocates buffer to for each line and list of tokens
 *
 */
void allocate_memory(void)
{
	char *line;
	char **token_list;
	const int line_size = 1024;

	line = malloc(sizeof(*line) * line_size);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token_list = malloc(sizeof(*token_list) * 55);
	if (token_list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global->line = line;
	global->token_list = token_list;
}
