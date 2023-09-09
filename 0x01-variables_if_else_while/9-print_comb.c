#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		putchar('0' + num);
		putchar(',');
		putchar(' ');
	}
	return (0);
}
