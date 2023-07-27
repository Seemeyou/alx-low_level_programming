#include "lists.h"
#include <stdio.h>
#include <string.h>

/**
 * _strlen - Computes the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: The pointer to the head of the linked list.
 * @str: The string to be added in the new node.
 *
 * Return: The address of the new node, or NULL on failure.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = _strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
