#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
	list_t *tempholder;

	while (head)
	{
		tempholder = head->next;
		free(head->str);
		free(head);
		head = tempholder;
	}
}

