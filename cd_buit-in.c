#include "shell.h"

/**
 * builtin_cd - changes working directory
 * @args: argument passed
 *
 * Return: 0 on success.
*/

int builtin_cd(char *args[])
{
	char *home_dir, *directory, *pwd;
	int ret;

	if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			perror("cd");
			return (1);
		}

		ret = chdir(home_dir);
	}
	else
	{
		directory = args[1];
		ret = chdir(directory);
	}

	if (ret == -1)
	{
		perror("cd");
		return (1);
	}

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("cd");
		return (1);
	}

	setenv("PWD", pwd, 1);
	free(pwd);

	return (0);
}
