#include "monty.h"

/**
 * get_tok - Get the number of gokens for a string
 * @str: string
 * Return: numbe of tokens
 */
unsigned int get_tok(char *str)
{
	unsigned int count = 0, in_word = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (str[i] == ' ')
			in_word = 0;
	}
	return (count);
}

/**
 * tokenize - a function that tokenizes a string
 * @line: string to tokenize
 * Return: 0
 */
void tokenize(char *line)
{
	unsigned int i = 0;

	data.args[i] = strtok(line, " ");
	for (i = 1; i < data.tokens; i++)
		data.args[i] = strtok(NULL, " ");
	data.args[i] = NULL;
}

/**
 * mod_line - Modifies a string
 * @s: string to Modify
 * Description: Replaces a '\n' character in a string with '\0'
 */

void mod_line(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
}

/**
 * is_number - a function that checks if the command input is a number
 * @s: the command to be checked
 * Return: 0
 */
int is_number(char *s)
{
	int i = 0;

	if (s[i] == '-')
	i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
