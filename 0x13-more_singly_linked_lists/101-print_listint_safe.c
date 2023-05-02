#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	size_t count = 0;
	int loop_detected = 0;

	if (head == NULL)
		exit(98);

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		current = head->next;

		if (current == head)
		{
			loop_detected = 1;
			break;
		}

		head = current;
	}

	if (loop_detected)
		printf("Loop starts at [%p]\n", (void *)head);

	return (count);
}

