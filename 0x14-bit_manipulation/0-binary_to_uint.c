#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary number as a string.
 *
 * Return: The converted unsigned int, or 0 if b is NULL or contains
 *         non-binary characters.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int len = 0;
	int i;

	if (b == NULL)
		return (0);

	while (b[len])
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	for (i = 0; b[i]; i++)
	{
		result <<= 1;
		if (b[i] == '1')
			result += 1;
	}

	return (result);
}
