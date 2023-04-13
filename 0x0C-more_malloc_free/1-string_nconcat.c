#include "main.h"

/**
  *string_nconcat - concatenates n bytes of a string to another string
  *@s1: string to append to
  * @s2: string to concatenate from
  * @n: number of bytes from s2 to concatenate to s1
  *
  *Return: pointer to the resulting string
  */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int len1, len2, size;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (n >= len2)
		n = len2;
	size = len1 + n + 1;
	s = malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	memcpy(s, s1, len1);
	memcpy(s + len1, s2, n);
	s[len1 + n] = '\0';
	return (s);
}
