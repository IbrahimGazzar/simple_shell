#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * path_handle - allow commands to execute with full path
 * @args: arguements passed to the shell
 * @env: array of enviromental variables
 * Return: 0 on success, 1 on error
 */
int path_handle(char **args, char **env)
{
	char *vari = malloc(sizeof(char) * 1600), **dirs = get_path(vari, env);
	char *real_path = malloc(sizeof(char) * 100);
	int i = 0, status;
	pid_t child;

	while (dirs[i] != NULL)
	{
		if (real_path == NULL)
			break;
		_strcpy(real_path, dirs[i]);
		_strcat(real_path, "/");
		_strcat(real_path, args[0]);
		if (access(real_path, F_OK) != -1)
			break;
		i++;
	}
	free(dirs);
	free(vari);
	if (real_path == NULL || access(real_path, F_OK) == -1)
	{
		free(real_path);
		return (1);
	}
	child = fork();
	if (child == -1)
		return (1);
	if (child == 0)
	{
		if (execve(real_path, args, NULL) == -1)
		{
			free(real_path);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(real_path);
	}
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 1);
}
