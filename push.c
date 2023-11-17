#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @value:digit
 * @line_number: line number of the opcode in the Monty file
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
