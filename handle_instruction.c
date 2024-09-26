#include "monty.h"

/**
 * handle_instruction - Executes the opcode function
 * @opcode: Opcode string
 * @arg: Argument for the opcode (if applicable)
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 */
void handle_instruction(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
		return;
	}

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

