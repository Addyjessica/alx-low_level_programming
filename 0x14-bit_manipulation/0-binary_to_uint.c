
#include "main.h"

/**
 * binary_to_uint - function converts a binary number to an unsigned int.
 * @b: pointer to a string containing a binary number
 *
 * Return: number as int, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int number;

	number = 0;
	if (!b)
		return (0);
	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{
		number <<= 1;
		if (b[x] == '1')
			number += 1;
	}
	return (number);
}


