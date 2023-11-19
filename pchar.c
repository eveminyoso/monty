#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (is_ascii(current->n))
	{
		putchar(current->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
