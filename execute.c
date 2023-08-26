#include "monty.h"

/**
 * execute - executes opcodes
 */
void execute(void)
{
	char line[BUFF_SIZE];

	while (fgets(line, BUFF_SIZE, data.file))
	{
		data.args = NULL;
		mod_line(line);
		data.tokens = get_tok(line);
		if (data.tokens == 0)
		{
			data.line_nu++;
			continue;
		}
		data.args = malloc(sizeof(char *) * (data.tokens + 1));
		if (!data.args)
		{
			fprintf(stderr, "Error: malloc failed\n");
			cleanup(1);
		}
		tokenize(line);
		if (data.args[0][0] == '#')
		{
			data.line_nu++;
			free(data.args);
			continue;
		}
		operate();
		free(data.args);
	}

	cleanup(0);
}
