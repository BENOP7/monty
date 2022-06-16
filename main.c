#include <stdlib.h>
#include "monty.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

stack_t *head = NULL;

/**
 * main - Monty program
 *
 * @argc: size of argument list
 * @argv: list of arguments
 *
 * Return: 0 if SUCCESS, on failure returns non-zero
 */
int main(int argc, char **argv)
{
	char line[128];
	int line_no = 0;
	int len = 128;
	char *token;
	char *list[] = {NULL, "-"};
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/*Read and interprete every line */

	do {
		if (fgets(line, len, file) == 0)
			break;
		++line_no;
		line[strlen(line) - 1] = '\0';
		token = strtok(line, " ");
		if (token)
			list[0] = token;
		token = strtok(NULL, " ");
		if (token)
			list[1] = token;
		interprete(list, line_no);
	} while (1);
	free_stackint(head);
	fclose(file);
	return (0);
}
