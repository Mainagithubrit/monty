#include "monty.h"

/**
 * operate - performs operation on monty byte code
 */
void operate(void)
{
	int i = 0;
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", op_div},
		{"mod", mod},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{NULL, NULL}
	};

	while (instruct[i].opcode)
	{
		if (strcmp(data.args[0], instruct[i].opcode) == 0)
		{
			instruct[i].f(&data.head, data.line_nu);
			break;
		}
		i++;
	}
	if (instruct[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", data.line_nu, data.args[0]);
		cleanup(1);
	}
	data.line_nu++;
}

/**
 * push - perform monty push operation
 * The push operation add a new stack to the data stack
 * @stack: head pointer to stack structure
 * @line_number: current opcode line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (data.tokens < 2 || !is_number(data.args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		cleanup(1);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup(1);
	}

	new->n = atoi(data.args[1]);
	new->prev = NULL;
	/* Special case for if head is points to NULL) */
	if (!*(stack))
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	data.stacks++;
}

/**
 * pall - prints all the element in the stack
 * @stack: head pointer to stack structure
 * @line_number: current opcode line number
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = *stack;
	size_t i = 0;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		i++;
		tmp = tmp->next;
	}
}

/**
 * pint - Print the data at the top most stack
 * @stack: head pointer to stack structure
 * @line_number: current opcode line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp)
		printf("%d\n", tmp->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup(1);
	}
}

/**
 * pop - Deletes the last element in the stack
 * @stack: head pointer to stack structure
 * @line_number: current opcode line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup(1);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
	data.stacks--;
}
