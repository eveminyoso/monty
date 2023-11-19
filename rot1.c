#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = NULL;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
