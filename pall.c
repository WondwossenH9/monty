#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pall - checks if the stack is empty and, if not, iterates through the stack
 * @stack: the stack
 * Return: nothing
 */
void pall(stack_t *stack)
{
	if (!stack)
	{
		return;
	}
	stack_t *node = stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
