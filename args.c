#include "shell.h"

/**
 * arg - handles command lines with arguments.
 * @input: input from the command line
 * @av_ptr: pointer to arguments
 *
 * Return: Nothing.
 */

void arg(char *input, char ***av_ptr)
{
	int ac = 0;
	int capacity = 10;
	char **av, *token, **temp;

	av = malloc(capacity * sizeof(char *));

	if (av == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		if (ac >= capacity)
		{
			capacity *= 2;
			temp = realloc(av, capacity * sizeof(char *));
			if (temp == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			av = temp;
		}

		av[ac] = _strdup(token);
		if (av[ac] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		ac++;
		token = strtok(NULL, " \t\n");
	}
	av[ac] = NULL;
	*av_ptr = av;
}
