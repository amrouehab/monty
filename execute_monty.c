#include "monty.h"

#define LINE_BUFFER_SIZE 1024

/**
 * execute_monty - Executes the Monty bytecode from a file
 * @filename: Name of the file
 */
void execute_monty(char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line;
	size_t len = LINE_BUFFER_SIZE;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;

	line = malloc(sizeof(char) * LINE_BUFFER_SIZE);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode != NULL && opcode[0] != '#')
			handle_instruction(opcode, arg, &stack, line_number);
	}

	fclose(file);
	free(line);
	/* Free the stack here */
}

