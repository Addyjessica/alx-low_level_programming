#include <stdio.h>
#include "main.h"

/**
 * _atoi -function to  convert a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */

int _atoi(char *s)
{
	int a, b, n, len, y, digit;

	a = 0;
	b = 0;
	n = 0;
	len = 0;
	y = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;
	while (a < len && y == 0)
	{
		if (s[a] == '-')
			++b;
		if (s[a] >= '0' && s[a] <= '9')
		{
			digit = s[a] - '0';
			if (b % 2)
				digit = -digit;
			n = n * 10 + digit;
			y = 1;
			if (s[a + 1] < '0' || s[a + 1] > '9')
				break;
			y = 0;
		}
		a++;
	}
	if (y == 0)
		return (0);
	return (n);
}

/**
 * main - program to multiply two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int ans, c, v;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	c = _atoi(argv[1]);
	v = _atoi(argv[2]);
	ans = c * v;

	printf("%d\n", ans);
	return (0);
}
