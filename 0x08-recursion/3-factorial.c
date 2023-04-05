#include "main.h"

/**
  *factorial - returns the factorial
 * @n: the number which the factorial is returned from
 *
 * Return: factorial of n
 */


int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
