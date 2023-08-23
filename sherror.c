#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * strfree - frees strings as necessary
 * @str: corresponds to 'cmd' from shell
 * @strarr: corresponds to 'argv' from shell
 *
 * Return: no return value
 */
void strfree(char *str, char **strarr)
{
	free(str);
	free(strarr);
}
/**
 * sherror: handles errors
 * @src: name of source file
 * @str: corresponds to 'cmd' from shell
 * @strarr: corresponds to 'argv' from shell
 *
 * Return: no return value
 */
void sherror(char *src, char *str, char **strarr)
{
	strfree(str, strarr);
	perror(src);
	exit(EXIT_FAILURE);
}
