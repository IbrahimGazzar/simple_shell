#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

sig_atomic_t interrupted = 0;
/**
 * handle_interrupt - handles interrupts to the process
 * @signum: number of the signal
 *
 * Return: no return value
 */
void handle_interrupt(int signum)
{
	(void)signum;
	interrupted = 1;
}
/**
 * main - function that begins execution of the program
 * @argc: number of given arguements
 * @argv: array of string arguements
 * @env: array of enviroment variables
 *
 * Return: always 0
 */
int main(int argc, char **argv, char **env)
{
	if (argc != 1)
		exit(97);
	signal(SIGINT, handle_interrupt);
	shell(argv[0], env, &interrupted);
	return (0);
}
