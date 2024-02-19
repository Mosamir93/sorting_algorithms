#include "sort.h"

/**
 * swap - swaps two nodes in a list
 * @list: head of th list
 * @temp: the node to be moved forward
 * @current: the node to be moved backwards
*/
void swap(listint_t **list, listint_t **temp, listint_t *current)
{
	if ((*temp)->prev)
		(*temp)->prev->next = current;

	if ((current)->next)
		current->next->prev = *temp;

	(*temp)->next = (current)->next;
	(current)->prev = (*temp)->prev;
	(current)->next = (*temp);
	(*temp)->prev = current;
    (*temp) = (current)->prev;
	if (!(current)->prev)
		*list = current;
}

/**
 * 
 * 
 * 
*/

void cocktail_sort_list(listint_t **list)
{
    int flag = 1;
    listint_t *start, *end, *current;

    start = NULL;
    end = NULL;
    current = *list;
    while (flag)
    {
        flag = 0;
        while (current->next != end)
        {
            if (current->n > current->next->n)
            {
                swap(list, &current, (current->next));
                flag = 1;
                print_list(*list);
            }
            current = current->next;
        }
        if (!flag)
            break;
        flag = 0;
        end = current;
        current = current->prev;
        while (current->prev != start)
        {
            if (current->n < current->prev->n)
            {
                swap(list, &(current->prev), current);
                flag = 1;
                print_list(*list);
            }
            current = current->prev;
        }
        start = current;
        current = current->next;
    }
}
