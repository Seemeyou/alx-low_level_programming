#include "main.h"

/**
  *_puts_recursion - function
  *@s: this is the input
  *Return: 0 (success)
  */

void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
		_putchar('\n');
}
