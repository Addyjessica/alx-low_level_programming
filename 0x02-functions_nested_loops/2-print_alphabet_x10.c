#include "main.h"
/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase,
 * followed by a new line
 */
void print_alphabet_x10(void)
{
	char ja;
	int i;

	i = 0;

	while (i < 10)
	{
		ja = 'a';
		while (ja <= 'z')
		{
			_putchar(ja);
			ja++;
		}
		_putchar('\n');
		i++;
	}
}
