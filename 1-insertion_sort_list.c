#include "sort.h"

/**
 * swap_nd - changes the nodes of a doubly linked list
 * @h: is a pointer to the head of the list
 * @n1: the first node to swap
 * @n2: the other node to swap
 *
 */
void swap_nd(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts the list of integers in a
 *                       doubly linked list using insertion sort
 * @list: pointer
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nd(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
