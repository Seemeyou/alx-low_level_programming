#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * perform_operation - Performs the requested operation.
 * @num1: The first number.
 * @op: The operator.
 * @num2: The second number.
 *
 * Return: The result of the operation.
 */
int perform_operation(int num1, char *op, int num2)
{
	if (*op == '+')
		return (op_add(num1, num2));
	if (*op == '-')
		return (op_sub(num1, num2));
	if (*op == '*')
		return (op_mul(num1, num2));
	if (*op == '/')
		return (op_div(num1, num2));
	if (*op == '%')
		return (op_mod(num1, num2));

	return (0);
}

/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	if (op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = perform_operation(num1, op, num2);
	printf("%d\n", result);

	return (0);
}
