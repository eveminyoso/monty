#include "monty.h"
/**
 *main - runs the bytecodes line by line
 *@argc:number of arguments
 *@argv:argument array
 *Return:0
 */
int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char opcode[5];
	char input_string[20];
	FILE *file = fopen(argv[1], "r");

	stack_t *stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
				push(&stack, input_string, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(&stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(&stack, line_number);
		else if (strcmp(opcode, "add") == 0)
			add(&stack, line_number);
		else if (strcmp(opcode, "nop") == 0)
			nop(&stack, line_number);
		else if (strcmp(opcode, "sub") == 0)
			sub(&stack, line_number);
		else if (strcmp(opcode, "div") == 0)
			div_op(&stack, line_number);
		else if (strcmp(opcode, "mul") == 0)
			mul(&stack, line_number);
		else if (strcmp(opcode, "mod") == 0)
			mod(&stack, line_number);
		else if (strcmp(opcode, "pchar") == 0)
			pchar(&stack, line_number);
		else if (strcmp(opcode, "pstr") == 0)
			pstr(&stack, line_number);
		else if (strcmp(opcode, "rotl") == 0)
			rotl(&stack, line_number);
		else if (strcmp(opcode, "rotr") == 0)
			rotr(&stack, line_number);
		else if (strcmp(opcode, "stack") == 0)
			shtack(&stack, line_number);
		else if (strcmp(opcode, "queue") == 0)
			queue(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
