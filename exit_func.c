#include "shell.h"

/**
 * exit_func - Handles the built-in exit command of the shell
 *
 * @args: arguments
 * Return: 0 to exit.
 */

int exit_func(char *args[])
{
	if (args[1])
	{
		char *message = "Usage: exit\n";

		write(STDERR_FILENO, message, _strlen(message));
		return (0);
	}
	exit(0);
}
