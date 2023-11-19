#include "monty.h"
/**
 * shtack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void shtack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
		(*stack)->mode = 0;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack != NULL)
		(*stack)->mode = 1;
}
