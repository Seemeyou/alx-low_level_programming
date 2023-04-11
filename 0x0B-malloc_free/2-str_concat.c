#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */

char *str_concat(char *s1, char *s2)
{
	size_t s1_len = s1 ? strlen(s1) : 0;
	size_t s2_len = s2 ? strlen(s2) : 0;
	size_t concat_len = s1_len + s2_len + 1;

	char *concat_str = malloc(concat_len * sizeof(char));

	if (concat_str == NULL)
	{
		return (NULL);
	}
	if (s1 != NULL)
	{
		strcpy(concat_str, s1);
	}
	if (s2 != NULL)
	{
		strcpy(concat_str + s1_len, s2);
	}

	return (concat_str);
}
