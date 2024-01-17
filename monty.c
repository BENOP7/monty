#include "monty.h"
#include <string.h>

int main(int ac, char **av)
{
	FILE *file = NULL;
	char *line = NULL;
	char *opcode;
	char *operand;
	char *opcode_list[] = {"push", "pall"};
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	void (*func[])(stack_t **stack, unsigned int line_number, const int n) = {push, pall};
	int i;

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

	line = malloc(sizeof(*line) * 1024);

	fgets(line, 1024, file);
	
	opcode = strtok(line, " ");
	operand = strtok(NULL, " ");

	for (i = 0; i < 2; i++)
	{
		if (strcmp(opcode, opcode_list[i]) == 0)
		{
			func[i](my_stack, -1, 
		}
	}
	

}
