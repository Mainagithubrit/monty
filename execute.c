#include "monty.h"

/**
 * execute - This functions allocates space for a character of arrays
 * Return: 0
 */

void execute(void)
{
	char line[BUFF_SIZE];

	while (fgets(line, BUFF_SIZE, file))
	{
	args = NULL;
	mod_line(line);
	tokens = get_tok(line);
	if (tokens == 0)
	{
		line_nu++;
		continue;
	}
	args = malloc(sizeof(char *) * (tokens + 1));
	if (!args)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup(1);
	}
	tokenize(line);
	operate();
	free(args);
}

	cleanup(0);
}

