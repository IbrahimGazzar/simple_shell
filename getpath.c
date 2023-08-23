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
char **get_path()
{
	extern char **environ;
	int i;
	char *vari;
	char *token = NULL;
	char **dirs = malloc(sizeof(char *) * 50);

	if (dirs == NULL)
		return (NULL);
	vari = malloc(sizeof(char) * 1600);
	if (vari == NULL)
	{
		free(dirs);
		return (NULL);
	}
	for (i = 0; environ[i] != 0; i++)
	{
		_strcpy(vari, environ[i]);
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
