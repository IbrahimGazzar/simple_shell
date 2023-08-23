#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * get_path - gets potential pathes
 * @vari: parameter to hold the paths
 * @env: array of enviromental variables
 *
 * Return: array containing directories to check
 */
char **get_path(char *vari, char **env)
{
	int i;
	char *token = NULL;
	char **dirs = malloc(sizeof(char *) * 50);

	if (dirs == NULL)
		return (NULL);
	for (i = 0; env[i] != 0; i++)
	{
		vari = _strcpy(vari, env[i]);
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
