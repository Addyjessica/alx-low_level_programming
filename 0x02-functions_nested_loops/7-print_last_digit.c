#include "main.h"
/**
 * print_last_digit - prints the last digit of an integer
 * @a: The integer to print the last digit from
 * Return: the last digit
 */
int print_last_digit(int a)
{
	int i;

	if (a < 0)
	{
		a = -a;
	}
	i = a % 10;
	if (i < 0)
		i = -i;
	_putchar(i + '0');
	return (i);
}
