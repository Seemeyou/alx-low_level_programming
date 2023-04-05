#include "main.h"

int _sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - calculates the natural square root
 * @n: The number to get the squar root of
 *
 * Return: The natural square root of n, or -1 if n has no square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return _sqrt_helper(n, 1);
}

/**
 * _sqrt_helper - Recursive helper function for _sqrt_recursion
 * @n: The number to get the square root of
 * @i: candidate root
 *
 * Return: The natural square root of n or -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
		return -1;
	if (i * i == n)
		return i;

	return _sqrt_helper(n, i + 1);
}
