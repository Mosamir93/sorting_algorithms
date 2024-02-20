#include "sort.h"

/**
 * get_max - gets the maximum integer in an array
 * @array: the array to get the max from
 * @size: size of the array
 * Return: the maximum integer
 */

int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * fill_zeros - fills the count array with zeros
 * @array: the array to be filled
 * @size: size of the array
 */

void fill_zeros(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}

/**
 * count_sort - sorts the array using counting sort
 * according to position provided
 * @array: the array to be sorted
 * @size: size of the array
 * @pos: position to sort according to
 */

void count_sort(int *array, size_t size, int pos)
{
	int *count, *array_b;
	size_t i;

	count = malloc(10 * sizeof(int));
	if (!count)
		return;
	fill_zeros(count, 10);
	array_b = malloc(size * sizeof(int));
	if (!array_b)
		return;
	for (i = 0; i < size; i++)
	{
		++count[(array[i] / pos) % 10];
	}
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];
	for (i = size - 1; i > 0; i--)
	{
		array_b[--count[(array[i] / pos) % 10]] = array[i];
	}
	array_b[--count[(array[i] / pos) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = array_b[i];
	print_array(array, size);
	free(count);
	free(array_b);
}

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, pos;

	if (!array || size < 2)
		return;
	max = get_max(array, size);
	for (pos = 1; max / pos; pos *= 10)
	{
		count_sort(array, size, pos);
	}

}
