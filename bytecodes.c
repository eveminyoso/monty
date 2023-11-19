#include "monty.h"
/**
 *main - runs the bytecodes line by line
 *@argc:number of arguments
 *@argv:argument array
 *Return:0
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	int value;
	unsigned int line_number = 0;
	char opcode[5];
	char input_string[20];
	FILE *file = fopen(argv[1], "r");

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
				push(&stack, value, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
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
