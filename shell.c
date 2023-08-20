#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

void shell(char *src)
{
	pid_t child;
	int papa;
	size_t size = 0;
	char *cmd = NULL;
	char *argv[2];
	char prompt[] = "($) ";
	int inter = isatty(STDIN_FILENO);
	while (1)
	{
		if (inter == 1)
			write(1, prompt, sizeof(prompt) - 1);
		if (getline(&cmd, &size, stdin) == -1)
			break;
		if (cmd == NULL)
			sherror(src, cmd);
		if (_strcmp(cmd, "\n") == 0)
			continue;
		cmd[strcspn(cmd, "\n")] = '\0';
		argv[0] = strtok(cmd, " ");
		argv[1] = NULL;
		child = fork();
		if (child == -1)
			sherror(src, cmd);
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				sherror(src, cmd);
		}
		else
		{
			wait(&papa);
		}
	}
	free(cmd);
}
