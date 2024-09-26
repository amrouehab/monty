#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: The current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);  /* Remove top element */
	(*stack)->n = sum;
}

