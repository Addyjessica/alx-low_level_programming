#include <unistd.h>


/**
 * _putcharr - writes the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putcharr(char c)
{
	return (write(1, &c, 1));
}

