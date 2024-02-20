#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (!b->prev)
		*list = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail Shaker Sort algorithm
 * @list: Pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL;
	listint_t *end = NULL;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		end = current;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
