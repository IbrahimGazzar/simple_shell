#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * shell - function that executes the shell
 * @src: executing file
 *
 * Return: no return value
 */
void shell(char *src)
{
	pid_t child;
	int papa;
	size_t size = 0;
	char *cmd = NULL;
	char *argv[2];

	while (1)
	{
		printf("($) ");
		if (getline(&cmd, &size, stdin) == -1 || cmd == NULL)
		{
			perror(src);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		cmd[strcspn(cmd, "\n")] = '\0';
		argv[0] = strtok(cmd, " ");
		argv[1] = NULL;
		child = fork();
		if (child == -1)
		{
			perror(src);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(src);
				free(cmd);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&papa);
		}
	}
	free(cmd);
}
