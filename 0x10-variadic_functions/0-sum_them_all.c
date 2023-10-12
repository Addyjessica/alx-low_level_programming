#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum.
 * @n: The number of paramters passed to the function.
 * @...: A variable number of paramters to calculate the sum of.
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ar;
	unsigned int a, sum = 0;

	va_start(ar, n);

	for (a = 0; a < n; a++)
		sum += va_arg(ar, int);

	va_end(ar);

	return (sum);
}

