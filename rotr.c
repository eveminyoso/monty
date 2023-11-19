#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	stack_t *second_last = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
