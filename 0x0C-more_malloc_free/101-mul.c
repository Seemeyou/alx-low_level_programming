#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _isdigit - checks if a string contains only digits
 * @str: the string to check
 *
 * Return: 1 if str contains only digits, 0 otherwise
 */
int _isdigit(char *str)
{
	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
		return (0);
		str++;
	}
	return (1);
}

/**
 * multiply - multiplies two positive numbers represented as strings
 * @num1: the first number
 * @num2: the second number
 *
 * Return: a string containing the result of the multiplication
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry = 0, sum;
	char *result;

	while (num1[len1])
		len1++;

	while (num2[len2])
		len2++;

	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
		sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
		carry = sum / 10;
		result[i + j + 1] = (sum % 10) + '0';
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}
	while (*result == '0' && *(result + 1) != '\0')
		result++;
	return (result);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	num1 = argv[1];
	num2 = argv[2];
	if (!_isdigit(num1) || !_isdigit(num2))
	{
		printf("Error\n");
		return (98);
	}
	result = multiply(num1, num2);
	if (!result)
	{
		printf("Error\n");
		return (98);
	}
	printf("%s\n", result);
	free(result);
	return (0);
}
