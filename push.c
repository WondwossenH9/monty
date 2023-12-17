#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number
 * @arg: pointer to argument
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	long int value = strtol(arg, NULL, 10);

	if (value < INT_MIN || value > INT_MAX)
	{
		fprintf(stderr, "L%u: argument out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "L%u: Error: malloc failed\n, line_number");
		exit(EXIT_FAILURE);
	}
	new_node->n = (int) value;
	new_node->prev = NULL;
	new_node->next = *stack;
	*stack = new_node;
}
