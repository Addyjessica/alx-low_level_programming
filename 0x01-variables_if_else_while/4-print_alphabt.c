#include <stdio.h>
/**
 * main - Entry point 
 * Return: 0
 */
int main(void)
{
	char lcase;

	for (lcase = 'a'; lcase <= 'z'; lcase++)
	{
		if (lcase != 'q' && lcase != 'e')
		{
			putchar(lcase);
		}
	}
	putchar('\n');
	return (0);
}
