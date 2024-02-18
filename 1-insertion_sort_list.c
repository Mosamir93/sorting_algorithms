#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the list's head
 */

void insertion_sort_list(listint_t **list)
{
	int key;
	listint_t *current, *temp;

	if (!list || !(*list) || !(*list)->next)
		return
			current = (*list)->next;
	while (current)
	{
		key = current->n;
		temp = current->prev;
		while (temp && temp->n > key)
		{
			if (temp->prev)
				temp->prev->next = current;

			if (current->next)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;
			temp = current->prev;

			if (!current->prev)
				*list = current;
			print_list((const listint_t *)*list);
		}
		current = current->next;
	}
}
