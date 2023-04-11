#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all arguments
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to new string, or NULL
 */

char *argstostr(int ac, char **av)
{
	int i, j, k;
	char *l;
	int len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}
	l = malloc(sizeof(char) * len);
	if (l == NULL)
		return (NULL);
	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			l[k++] = av[i][j];
		l[k++] = '\n';
	}
	l[k] = '\0';
	return (l);
}
