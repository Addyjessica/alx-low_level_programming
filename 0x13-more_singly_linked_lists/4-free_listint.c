#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: pointer to the listint_t list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp_cont;

	while (head)
	{
		temp_cont = head->next;
		free(head);
		head = temp_cont;
	}
}

