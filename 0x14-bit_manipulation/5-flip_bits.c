#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * from one number to another
 * @n: num1
 * @m: num2
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x = 63;
	int count = 0;
	unsigned long int current;
	unsigned long int raised_power = n ^ m;

	for (; x >= 0; x--)
	{
		current = raised_power >> x;
		if (current & 1)
			count++;
	}
	return (count);
}

