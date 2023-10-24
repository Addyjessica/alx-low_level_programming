
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given index
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a = 0;
	listint_t *newnode;
	listint_t *temp_cont = *head;

	newnode = malloc(sizeof(listint_t));
	if (!newnode || !head)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	for (; temp_cont && a < idx; a++)
	{
		if (a == idx - 1)
		{
			newnode->next = temp_cont->next;
			temp_cont->next = newnode;
			return (newnode);
		}
		else
			temp_cont = temp_cont->next;
	}

	return (NULL);
}

