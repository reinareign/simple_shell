#include "shell.h"

/**
 * prompt - display the shell prompt.
 *
 * Return: nothing.
 */
void prompt(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * process_input - Process the user input.
 *
 * @lineptr: a pointer to the input line.
 * Return: Parsed arguments (NULL-terminated).
 */
char **process_input(char *lineptr)
{
	char **argv = NULL;

	arg(lineptr, &argv);
	return (argv);
}

/**
 * handle_builtin_commands - Handle builtin shell commands.
 *
 * @argv: Array of arguments.
 * Return: 0 on success, 1 on failure, -1 to exit the shell.
 */
int handle_builtin_commands(char **argv)
{
	int status = 0;

	if (argv != NULL && argv[0] != NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			status = exit_func(argv);
			if (status != 0)
			{
				write(STDERR_FILENO, "Exit command failed.\n", 21);
				return (-1);
			}
		}
		else if (_strcmp(argv[0], "cd") == 0)
		{
			status = builtin_cd(argv);
			if (status != 0)
				write(STDERR_FILENO, "cd command failed.\n", 19);
		}
		else if (_strcmp(argv[0], "env") == 0)
		{
			env();
		}
		else
		{
			execmd(argv);
		}
	}

	return (0);
}

/**
 * shell_loop - Main loop of the shell
 * Return: 0
 */
int shell_loop(void)
{
	char *linep = NULL, **argv;
	size_t n = 0;
	int i, status;
	ssize_t n_chars;

	while (1)
	{
		prompt();

		n_chars = getline(&linep, &n, stdin);
		if (n_chars == -1)
		{
			if (!feof(stdin))
				perror("getline");
			break;
		}

		argv = process_input(linep);
		status = handle_builtin_commands(argv);

		if (argv != NULL)
		{
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
		}
		free(linep);
		linep = NULL;

		if (status == -1)
			break;
	}
	free(linep);
	return (0);
}

/**
 * main - shell program
 * Return: 0 on success
 */
int main(void)
{
	return (shell_loop());
}
