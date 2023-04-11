#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - count the number of words in a string
 * @str: the string to count words in
 *
 * Return: the number of words in str
 */
static int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (*str == ' ')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}

	return (count);
}

/**
 * strtow - split a string into words
 * @str: the string to split
 *
 * Return: an array of words, or NULL if str is NULL
 */
char **strtow(char *str)
{
	char **words;
	int num_words;
	int word_len;
	int in_word = 0;
	int i = 0, j = 0, k = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	num_words = count_words(str);
	words = malloc(sizeof(char *) * (num_words + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < num_words; i++)
	{
		word_len = 0;
		while (str[j] != '\0')
		{
			if (str[j] == ' ')
			{
				if (in_word)
					break;
			}
			else
			{
				in_word = 1;
				word_len++;
			}
			j++;
		}
		while (str[j] != '\0' && str[j] == ' ')
			j++;
		words[i] = malloc(sizeof(char) * (word_len + 1));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		strncpy(words[i], str + j - word_len, word_len);
		words[i][word_len] = '\0';
		in_word = 0;
	}
	words[i] = NULL;

	return (words);
}
