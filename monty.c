#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_monty(argv[1]);
	return (0);
}

