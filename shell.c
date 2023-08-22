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
	char **argv = NULL;
	char prompt[] = "($) ";
	int inter = isatty(STDIN_FILENO);
	while (1)
	{
		cmd = NULL;
		argv = NULL;
		if (inter == 1)
			write(1, prompt, sizeof(prompt) - 1);
		if (getline(&cmd, &size, stdin) == -1)
		{
			strfree(cmd, argv);
		        exit(EXIT_SUCCESS);
		}
		if (cmd == NULL)
			sherror(src, cmd, argv);
		if (_strcmp(cmd, "\n") == 0)
			continue;
		strtrm(cmd);
		argv = cmd_args(cmd);
		if (argv == NULL)
			return;
		child = fork();
		if (child == -1)
			sherror(src, cmd, argv);
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				sherror(src, cmd, argv);
		}
		else
		{
			wait(&papa);
			strfree(cmd, argv);
		}
	}
}
