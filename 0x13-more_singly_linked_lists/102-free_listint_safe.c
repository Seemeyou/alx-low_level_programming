#include "lists.h"
#include <stddef.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;

	current = *h;
	while (current != NULL)
	{
		count++;
		temp = current->next;
		free(current);
		current = temp;

		/* Detect if there's a loop and set head to NULL */
		if (current == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (count);
}

