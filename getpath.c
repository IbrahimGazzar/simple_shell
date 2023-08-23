#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * get_path - gets potential pathes
 *
 * Return: array containing directories to check
 */
char **get_path(char *vari)
{
	extern char **environ;
	int i;
	char *token = NULL;
	char **dirs = malloc(sizeof(char *) * 50);

	if (dirs == NULL)
		return (NULL);
	for (i = 0; environ[i] != 0; i++)
	{
		vari = _strcpy(vari, environ[i]);
		vari = strtok(vari, "=");
		if (_strcmp(vari, "PATH") == 0)
			break;
	}
	token = strtok(NULL, ":");
	i = 0;
	while (token != NULL)
	{
		dirs[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	dirs[i] = NULL;
	return (dirs);
}
