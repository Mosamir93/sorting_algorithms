#include "sort.h"

/**
 * copy_elements - Copies elements from one array to another.
 * @dest: Pointer to the destination array where elements will be copied.
 * @src: Pointer to the source array from which elements will be copied.
 * @size: The number of elements to copy from the source to the destination.
 */
void copy_elements(int *dest, const int *src, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		dest[i] = src[i];
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted array.
 * @array: Pointer to the array of integers to be sorted.
 * @l: Pointer to the first element of the left sub-array.
 * @l_size: The number of elements in the left sub-array.
 * @r: Pointer to the first element of the right sub-array.
 * @r_size: The number of elements in the right sub-array.
 */
void merge(int *array, int *l, size_t l_size, int *r, size_t r_size)
{
	size_t i =   0, j =   0, k =   0;
	int *temp = malloc((l_size + r_size) * sizeof(int));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, l_size);
	printf("[right]: ");
	print_array(r, r_size);
	while (i < l_size && j < r_size)
	{
		if (l[i] <= r[j])
			temp[k++] = l[i++];
		else
			temp[k++] = r[j++];
	}
	copy_elements(temp + k, l + i, l_size - i);
	k += l_size - i;
	copy_elements(temp + k, r + j, r_size - j);
	k += r_size - j;
	printf("[Done]: ");
	print_array(temp, k);
	copy_elements(array, temp, k);
	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, l_size, r_size;
	int *l, *r;

	if (size < 2)
		return;

	mid = size / 2;
	l = array;
	r = array + mid;
	l_size = mid;
	r_size = size - mid;

	merge_sort(l, l_size);
	merge_sort(r, r_size);

	merge(array, l, l_size, r, r_size);
}
