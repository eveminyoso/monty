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
	process_file(file, &stack);
	fclose(file);
	free_stack(stack);
	return (0);
}
