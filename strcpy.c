#include "main.h"

/**
 * _strcpy - copy one string into another
 * @dest: pointer to the string to be copied into
 * @src: the source of the string
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
