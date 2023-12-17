#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define NUM_INSTRUCTIONS 2

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
};
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack_t *stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf(stderr, "error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 1;

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		char *opcode = strtok(line, " \n");
		int found = 0;

		for (int i = 0; i < NUM_INSTRUCTIONS; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number, strtok(NULL, " \n"));
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
