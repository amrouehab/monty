#include "monty.h"
#include <ctype.h>

/**
 * is_integer - Checks if a string is a valid integer
 * @str: The string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number
 * @arg: Argument to push (should be an integer)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int n;
	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

