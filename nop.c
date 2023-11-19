#include "monty.h"

/**
 * nop - does nothing
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the Monty bytecodes file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
