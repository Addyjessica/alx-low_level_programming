#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp_cont = *head;
	listint_t *current = NULL;
	unsigned int a = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp_cont);
		return (1);
	}

	while (a < index - 1)
	{
		if (!temp_cont || !(temp_cont->next))
			return (-1);
		temp_cont = temp_cont->next;
		a++;
	}


	current = temp_cont->next;
	temp_cont->next = current->next;
	free(current);

	return (1);
}

