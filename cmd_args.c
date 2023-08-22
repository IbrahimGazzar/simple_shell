#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * cmd_args - tokenize input into arguments
 * @cmd: input to be tokenized
 *
 * Return: array of arguements
 */

char **cmd_args(char *cmd)
{
	char **args;
	char *ptr;
	int i = 0;
	int k = 1;
	char *token;

	ptr = cmd;
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
			k++;
		ptr++;
	}
	args = malloc(sizeof(char *) * (k + 1));
	if (args == NULL)
		return (NULL);
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	return (args);
}
