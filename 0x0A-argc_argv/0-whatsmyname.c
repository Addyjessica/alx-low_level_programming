#include <stdio.h>
#include "main.h"

/**
 * main - program to print the name
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on succes
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
