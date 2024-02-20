#include "deck.h"

/**
 * cmpstr - a function that Compares two strings
 * @str1: first string to compare
 * @str2: second string to compare
 * Return: returns 0 if identical
 */

int cmpstr(char *str1, const char *str2)
{
	while (*str1 != '\0')
	{
		if (*str2 == '\0')
			return (*str1);
		if (*str2 > *str1)
			return (*str1 - *str2);
		if (*str1 > *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str2 != '\0')
		return (*str2);
	return (0);
}

/**
 * swap_cards - Swaps two nodes of doubly linked list
 * @node: pointer to pointer to node to swap
 * @deck: pointer to pointer to head of list
 */

void swap_cards(deck_node_t **node, deck_node_t **deck)
{
	deck_node_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*deck = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;
}

/**
 * Card - checks the node's card value
 * @node: node to check it's value
 * Return: integer from 1 to 52
 */

int Card(deck_node_t *node)
{
	char *cardnum[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King"};
	int value, i;
	const char *cnum;

	cnum = node->card->value;
	for (i = 0; i < 13;  i++)
		if (!cmpstr(cardnum[i], cnum))
		{
			i++;
			break;
		}

	value = i + (node->card->kind) * 13;

	return (value);
}

/**
 * sort_deck - sorts a poker cards deck
 * @deck: pointer to pointer to a doubly linked list
 */

void sort_deck(deck_node_t **deck)
{
	deck_node_t *head, *pre, *temp;

	if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
		return;

	head = *deck;
	while (head && head->next)
	{
		if (Card(head) > Card(head->next))
		{
			temp = head;

			swap_cards(&temp, deck);
			head = temp;
			pre = temp;

			while (pre && pre->prev)
			{
				if (Card(pre) < Card(pre->prev))
				{
					temp = pre->prev;

					swap_cards(&(temp), deck);

					pre = temp->next;
				}

				pre = pre->prev;
			}
		}
		head = head->next;
	}
}
