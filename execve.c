#include "shell.h"

/**
 * execmd - excutes a command passed to a shell process
 * @av: the command
 *
 * Return: nothing.
 */

void execmd(char **av)
{
	char *cmd = NULL, *passed_cmd = NULL;
	pid_t child_pid;

	if (av)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork:");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			cmd = av[0];
			passed_cmd = find_path(cmd);

			if (passed_cmd == NULL)
			{
				perror("No such file or directory");
				exit(EXIT_FAILURE);
			}

			if (execve(passed_cmd, av, NULL) == -1)
			{
				perror("execve:");
				free(passed_cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}

}
