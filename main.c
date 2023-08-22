#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * main - function that begins execution of the program
 * @argc: number of given arguements
 * @argv: array of string arguements
 *
 * Return: always 0
 */
int main(int argc, char **argv)
{
	if (argc != 1)
		exit(97);
        shell(argv[0]);
	return (0);
}
