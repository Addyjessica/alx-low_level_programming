#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return:  sum_of_data
 */
int sum_listint(listint_t *head)
{
	int sum_of_data = 0;
	listint_t *temp_cont = head;

	while (temp_cont)
	{
		sum_of_data += temp_cont->n;
		temp_cont = temp_cont->next;
	}

	return (sum_of_data);
}

