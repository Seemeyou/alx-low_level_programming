#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head node of the linked list
 *
 * Return: number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head->next;

	while (fast != NULL && fast < slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL)
		fast = fast->next;
		count++;
	}

	if (fast != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		count++;
	}

	while (fast != NULL && fast < slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL)
		fast = fast->next;
		count++;
	}

	if (fast != NULL)
	{
		printf("-> [%p] %d\n", (void *)slow, slow->n);
		count++;
	}

	return (count);
}
