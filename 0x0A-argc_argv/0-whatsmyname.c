#include <stdio.h>
/**
  *main - main function
  *@argc: The size of the argv array
  *@argv: An array containing the program command line arguments
  *
  *Return: always 0
  */

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);
	return (0);
}
