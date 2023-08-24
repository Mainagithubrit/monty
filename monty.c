#include "monty.h"

/**
 * main - executes monty scripting language
 * @ac: argument count
 * @av: argument vector to main
 * Return: 0 on success
 */

data_t data = {NULL, NULL, NULL, 0, 0, 1};

int main(int ac, char *av[])
{

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data.file = fopen(av[1], "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	execute();
	return (0);
}
