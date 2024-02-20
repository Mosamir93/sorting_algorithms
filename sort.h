#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void _swap(int *a, int *b);
int lomuto_Partition(int *array, int min, int max, size_t size);
void quicksort(int *array, int min, int max, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *l, size_t l_size, int *r, size_t r_size);
void copy_elements(int *dest, const int *src, size_t size);
void counting_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
