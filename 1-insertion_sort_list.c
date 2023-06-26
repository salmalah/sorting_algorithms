#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list head pointer
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *k;

	c = (*list)->next;
	if (!*list || !list)
		return;
	while (c)
	{
		k = c;
		while (k->prev != NULL && k->n < k->prev->n)
		{
			k->prev->next = k->next;
			if (k->next)
				k->next->prev = k->prev;
			k->next = k->prev;
			k->prev = k->prev->prev;
			k->next->prev = k;
			if (!k->prev)
				*list = k;
			else
				k->prev->next = k;
			print_list(*list);
		}
		c = c->next;
	}
}

