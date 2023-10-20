#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of memebers in a linked list
 * @h: pointer to the list_t list
 *
 * Return: n
 */
size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		a++;
		h = h->next;
	}
	return (a);

