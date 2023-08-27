#include "monty.h"

/**
 * rotl - implements the rotl opcode
 * @stack: pointer to stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	UNUSED(line_number);
	if (!tmp || !tmp->next)
		return;

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next->next = NULL;
}
