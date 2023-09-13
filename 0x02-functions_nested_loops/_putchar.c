#include "main.h"
	#include <unistd.h>
	/**
	 * _putchar - writes the character c to standardouput
	 * @c: The character to print
	 *
	 * Return: 1
	 * On error, -1 is returned, and error is set appropriately.
	 */
	int _putchar(char a)
	{
		return (write(1, &a, 1));
	}
