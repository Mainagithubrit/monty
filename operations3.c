#include "monty.h"

/**
 * mul - A function that implements the mod opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		cleanup(1);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}



/**
 * mod - A function that implements the mod opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanup(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup(1);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * pchar - A function that implements the pchar opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup(1);
	}
}
