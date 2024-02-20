#include "sort.h"

/**
 * b_merge - bitonic merge function
 * @array: to be merged
 * @start: starting point
 * @size: size of the array
 * @t_size: size of the whole array
 * @dir: direction up or down
 */

void b_merge(int *array, size_t start, size_t size, size_t t_size, int dir)
{
	size_t i, k;
	int temp;

	if (size > 1)
	{
		k = size / 2;
		for (i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		b_merge(array, start, k, t_size, dir);
		b_merge(array, start + k, k, t_size, dir);
	}
}

/**
 * s_recursive - recursive bitonic sort function
 * @array: to be sorted
 * @start: starting point
 * @size: size of the array
 * @t_size: size of the whole array
 * @dir: direction up or down
 */

void s_recursive(int *array, size_t start, size_t size, size_t t_size, int dir)
{
	size_t k;

	if (size > 1)
	{
		k = size / 2;
		printf("Merging [%lu/%lu] (", size, t_size);
		printf("%s):\n", (dir == 1) ? "UP" : "DOWN");

		print_array(array + start, size);

		s_recursive(array, start, k, t_size, 1);
		s_recursive(array, start + k, k, t_size, 0);

		b_merge(array, start, size, t_size, dir);
		printf("Result [%lu/%lu] (%s):\n", size, t_size, (dir == 1) ? "UP" : "DOWN");
		print_array(array + start, size);
	}
}

/**
 * bitonic_sort - function that sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	s_recursive(array, 0, size, size, 1);
}
