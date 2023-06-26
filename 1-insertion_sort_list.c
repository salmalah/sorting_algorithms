#include "sort.h"
/**
 * insertion_sort_list - Sorts list of integers in ascending order
 * @list: Pointer to the head of the
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *k, *m, *tmp;

	if (!list || !*list)
		return;
	k = (*list)->next;
	while (k != NULL)
	{
		m = k;
		k = k->next;
		while (m != NULL && m->prev && m->prev->n > m->n)
		{
			new = m->prev;
			new->next = m->next;
			if (m->next)
				m->next->prev = new;
			m->next = new;
			m->prev = new->prev;
			if (new->prev)
				new->prev->next = m;
			else
				*list = m;
			new->prev = m;
			print_list(*list);
		}
	}
}
