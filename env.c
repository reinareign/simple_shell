#include "shell.h"

/**
 * env - function that prints the current evironment.
 *
 * Return: nothing.
 */

void env(void)
{
	char **print_env = environ;
	size_t len = _strlen(*print_env);

	while (*print_env != NULL)
	{
		write(STDOUT_FILENO, *print_env, len);
		write(STDOUT_FILENO, "\n", 1);
		print_env++;
	}
}
