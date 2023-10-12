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
	va_list apr;
	unsigned int a, sum = 0;

	va_start(apr, n);

	for (a = 0; a < n; a++)
		sum += va_arg(apr, int);

	va_end(apr);

	return (sum);
}

