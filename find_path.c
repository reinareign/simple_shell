#include "shell.h"
/**
 * find_path - gets the path of a command to be executed on the shell.
 * @cmd: the command to find the path.
 *
 * Return: a pointer to the path.
 */
char *find_path(char *cmd)
{
	char *path = getenv("PATH"), *pathcpy, *pathtok, *file_path;
	int cmd_len, dir_len;
	struct stat buff;

	if (path)
	{
		pathcpy = _strdup(path);
		cmd_len = _strlen(cmd);
		pathtok = strtok(pathcpy, ":");
		while (pathtok != NULL)
		{
			dir_len = _strlen(pathtok);
			file_path = malloc(cmd_len + dir_len + 2);

			if (file_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			_strcpy(file_path, pathtok);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);

			if (stat(file_path, &buff) == 0)
			{
				free(pathcpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				pathtok = strtok(NULL, ":");
			}
		}
		free(pathcpy);
		if (stat(cmd, &buff) == 0)
			return (_strdup(cmd));
		return (NULL);
		}
	return (NULL);
}
