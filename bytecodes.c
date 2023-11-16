#include "monty.h"
/**
 *main - runs the bytecodes line by line
 *@argc:number of arguments
 *@argv:argument array
 *Return:0
 */
int main(int argc, char *argv[])
{
	stack_t *stack, *temp;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	char opcode[MAX_LINE_LENGTH];
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		if (sscanf(line, "%s", opcode) == 1)
		{
			execute_instruction(&stack, opcode, line_number);
		}
	}
	fclose(file);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
