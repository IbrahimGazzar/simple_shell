#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * get_cmd - get input from standard input
 * @cmd: string to hole the input
 * @argv: argument array
 *
 * Return: input after cleaning
 */
char *get_cmd(char *cmd, char **argv)
{
	size_t size = 0;
	int inter = isatty(STDIN_FILENO);

	if (inter == 1)
		write(1, "($) ", sizeof("($) ") - 1);
	if (getline(&cmd, &size, stdin) == -1)
	{
		strfree(cmd, argv);
		exit(EXIT_SUCCESS);
	}
	return (cmd);
}
/**
 * wtht_path - executes code when handle path fails
 * @src: source file name
 * @cmd: command line string
 * @argv: argument list
 *
 * Return: no return value
 */
void wtht_path(char *src, char *cmd, char **argv)
{
	pid_t child;

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
		wait(NULL);
		strfree(cmd, argv);
	}
}
/**
 * shell - function that executes the shell
 * @src: name of the source file
 * @env: array containing enviroment strings
 * @interrupted: flag that detects interrupts
 *
 * Return: no return value
 */
void shell(char *src, char **env, sig_atomic_t *interrupted)
{
	char *cmd = NULL, **argv = NULL;

	while (!(*interrupted))
	{
		cmd = NULL;
		argv = NULL;
		cmd = get_cmd(cmd, argv);
		if (cmd == NULL)
			sherror(src, cmd, argv);
		if (_strcmp(cmd, "\n") == 0)
			continue;
		strtrm(cmd);
		argv = cmd_args(cmd);
		if (argv == NULL)
			return;
		if (path_handle(argv, env) == 0)
		{
			strfree(cmd, argv);
			continue;
		}
		else
		{
			if (access(argv[0], F_OK) == -1)
			{
				strfree(cmd, argv);
				perror(src);
				continue;
			}
			wtht_path(src, cmd, argv);
		}
	}
	strfree(cmd, argv);
	(void)env;
}
