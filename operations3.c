#include "monty.h"

/**
 * mul - A function that implements the mul opcode
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
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanup(1);
	}
	n = (*stack)->n;
	if ((n < 'a' || n > 'z') && (n < 'A' || n > 'Z'))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanup(1);
	}
	printf("%c\n", n);
}

/**
 * pstr - implement the pstr opcode
 * @stack: A pointer that points to an allocated memory
 * @line_number: the current line number being implemented
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);
	while (tmp && tmp->n != 0 && (isupper(tmp->n) || islower(tmp->n)))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
