#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the stack
 * @value:digit
 * @line_number: line number of the opcode in the Monty file
 */
void push(stack_t **stack, const char *value, unsigned int line_number)
{
	const char *ptr = value;
	int num;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
	if (ptr[0] == '-')
	{
		ptr++;
	}
	for (; *ptr != '\0'; ++ptr)
	{
		if (!isdigit((unsigned char)*ptr))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	num = atoi(value);
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
