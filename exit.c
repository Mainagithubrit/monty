#include "monty.h"

/**
 * cleanup - takes care of exit and free for the program
 * @status: status
 */
void cleanup(int status)
{
	stack_t *tmp = data.head;

	clean_stack(tmp);
	if (status)
	{
		free(data.args);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	fclose(data.file);
	exit(EXIT_SUCCESS);
}

/**
 * clean_stack - Recursively frees the stack
 * @tmp: pointer to stack
 */
void clean_stack(stack_t *tmp)
{
	if (!tmp)
		return;
	clean_stack(tmp->next);
	free(tmp);
}
