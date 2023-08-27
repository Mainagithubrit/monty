#include "monty.h"

/**
 * swap - A function that implements the swap opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the line where an element is in a stack
 * Return: 0
 */

void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int nu;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanup(1);
	}
	nu = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = nu;
}

/**
 * add - A function that implements the add opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the line where an element is in a stack
 */

void add(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanup(1);
	}
	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * nop - A function that implements the nop opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the line where an element is in a stack
 * Return: 0
 */

void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
/**
 * sub - A function that implements the sub opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanup(1);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}

/**
 * op_div - A function that implements the div opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	unsigned int result;

	if (data.stacks < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		cleanup(1);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup(1);
	}
	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	pop(stack, line_number);
}
