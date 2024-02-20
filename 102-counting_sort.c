#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *array_b;
	size_t i, c_size;
	int k = 0;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = malloc((k + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i < size; i++)
	{
		++count[array[i]];
	}
	c_size = k;
	for (i = 1; i <= c_size; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	print_array(count, k + 1);
	array_b = malloc(size * sizeof(int));
	if (!array_b)
		return;
	for (i = size - 1; i > 0; i--)
	{
		array_b[--count[array[i]]] = array[i];
	}
	array_b[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
	{
		array[i] = array_b[i];
	}
	free(count);
	free(array_b);
}
