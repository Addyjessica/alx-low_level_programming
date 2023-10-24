#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start = head;
	listint_t *end = head;

	if (!head)
		return (NULL);

	while (start && end && end->next)
	{
		end = end->next->next;
		start = start->next;
		if (end == start)
		{
			start = head;
			while (start != end)
			{
				start = start->next;
				end = end->next;
			}
			return (end);
		}
	}

	return (NULL);
}


