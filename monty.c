#include "monty.h"

/**
 * main - executes monty scripting language
 * @ac: argument count
 * @av: argument vector to main
 * Return: 0 on success
 */

	stack_t *head = NULL;
	char **args = NULL;
	FILE *file = NULL;
	unsigned int tokens = 0;
	unsigned int stacks = 0;
	unsigned int line_nu = 1;

int main(int ac, char *av[])
{

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	execute();
	return (0);
}
