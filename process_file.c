#include "monty.h"
/**
 *process_file - processing logic
 *@file:given file
 *@stack:pointer to the stack
 */
void process_file(FILE *file, stack_t **stack)
{
	int value;
	unsigned int line_number = 0;
	char opcode[5];
	char input_string[20];
	
	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;
		if (opcode[0] == '#')
		{
			while (fgetc(file) != '\n')
				continue;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%s", input_string) == 1)
			{
				value = atoi(input_string);
				if (value == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
					exit(EXIT_FAILURE);
				}
				push(stack, value, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
				exit(EXIT_FAILURE);
			}
		} else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
