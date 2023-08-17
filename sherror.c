#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * sherror - print error message and exit process
 * @src: exe file name
 * @str: string to be freed
 *
 * Return: no return value
 */

void sherror(char *src, char *str)
{
 if (str != NULL)
  free(str);
 perror(src);
 exit(EXIT_FAILURE);
}
