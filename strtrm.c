#include "main.h"

/**
 * strtrm - puts a \0 instead of the first \n found in a string
 * @cmd: string to be edit
 *
 * Return: no return value
 */

void strtrm(char *cmd)
{
	char *ptr = cmd;

	while (*ptr != '\0')
	{
		if (*ptr == '\n')
		{
			*ptr = '\0';
			break;
		}
		ptr++;
	}
}
