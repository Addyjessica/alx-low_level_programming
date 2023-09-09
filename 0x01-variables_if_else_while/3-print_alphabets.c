#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	char ucase, lcase;

	for (ucase = 'a'; ucase <= 'z'; ucase++)
	{
		putchar(ucase);
	}
	for (lcase = 'A'; lcase <= 'Z'; lcase++)
	{
		putchar(lcase);
	}
	putchar('\n');
	return (0);
}
