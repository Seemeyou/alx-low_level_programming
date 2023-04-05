#include "main.h"

/*
   *_print_rev_recursion - prints a reverse string
   *@s: ths is the string tobe printed
   */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
