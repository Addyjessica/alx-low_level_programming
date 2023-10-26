#include"main.h"

/**
 * get_bit - prog returns the value of a bit at a given position
 * @n: number to check bits
 * @index: index at which to check bit
 *
 * Return: value of the bit, or -1 if there is an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int div, i;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	div = 1 << index;
	i = n & div;
	if (i == div)
		return (1);
	return (0);
}
