#ifndef _MONTY_H_
#define _MONTY_H_

/******************** Header Files ********************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/********************** Macros *************************/
#define BUFF_SIZE 1024
#define UNUSED(x) ((void)(x))


/********************** Structures ********************/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - data
 * @head: stack head pointer
 * @args: arguments
 * @file: file pointer
 * @tokens: tokens
 * @stacks: number of stacks
 * @line_nu: line number
 */

typedef struct data_s
{
	stack_t *head;
	char **args;
	FILE *file;
	unsigned int tokens;
	unsigned int stacks;
	unsigned int line_nu;
} data_t;

/********************* Global variables ****************/
extern data_t data;

/***************** Function Prototypes *****************/
void execute(void);
unsigned int get_tok(char *str);
void tokenize(char *line);
void operate(void);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void mod_line(char *s);
void cleanup(int status);
void clean_stack(stack_t *tmp);
int is_number(char *s);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

#endif
