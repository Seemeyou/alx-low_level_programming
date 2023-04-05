#include "main.h"
/**
  *wildcmp - compare two strings
  *@s1: pointer to the first string
  *@s2: pointer to the second string
  *
  *Return: 1 if identical, otherwise 0
  */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return 1;
		return (0);
	}
	if (*s1 == *s2)
		return wildcmp(s1 + 1, s2 + 1);
	return (0);
}
