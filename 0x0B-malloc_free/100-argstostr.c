#include "main.h"
#include <stdlib.h>

/**
*argstostr - function that concatenates arguments ofprogram
*@ac: number of arguments
*@av: the  array of arguments
*Return: pointer to concatenated string or NULL upon failure
*/

char *argstostr(int ac, char **av)
{
	int i, len, total_len = 0;
	char *str, *p;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
			len++;
		total_len += len + 1;
	}

	str = malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);

	p = str;
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			*p = av[i][len];
			len++;
			p++;
		}
		*p = '\n';
		p++;
	}
	*p = '\0';

	return (str);
}
