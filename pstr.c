#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode in the Monty file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int value;

	(void)line_number;
	while (current != NULL && current->n != 0 && is_ascii_printable(current->n))
	{
		value = current->n;
		putchar(value);
		current = current->next;
	}
	putchar('\n');
}
/**
 * is_ascii_printable - checks if the ASCII value is printable
 * @value: ASCII value to check
 * Return: 1 if printable, 0 otherwise
 */
int is_ascii_printable(int value)
{
	return (value >= 32 && value <= 126);
}
