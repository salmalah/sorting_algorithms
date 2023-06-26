#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list head pointer
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *c, *t, *k;

	if (!*list || !list || (*list)->next == NULL)
		return;
	c = (*list)->next;
	while (c)
	{
		k = c;
		c = c->next;
		while (k->prev != NULL && k->prev->n > k->n  && k)
		{
			t = k->prev;
			t->next = k->next;
			if (k->next)
				k->next->prev = t;
			k->next = t;
			k->prev = t->prev;
			if (!t->prev)
				*list = k;
			else
				t->prev->next = k;
			t->prev = k;
			print_list(*list);
		}
	}
}

