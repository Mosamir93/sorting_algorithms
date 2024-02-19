#include "sort.h"

/**
 * _swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: nothing
 */
void _swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_Partition - Lomuto partition scheme
 * @array: Array to sort
 * @min: Starting index of partition
 * @max: Ending index of partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int lomuto_Partition(int *array, int min, int max, size_t size)
{
    int pivot = array[max];
    int i = min -  1, j = min;

    while (j < max)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (j != i)
            {
                _swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
        j++;
    }
    if (max != i + 1)
    {
        _swap(&array[i + 1], &array[max]);
        print_array(array, size);
    }
    return i + 1;
}

/**
 * quicksort - quick sort recursive function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int pivot;

	if (min >= max)
		return;
	pivot = lomuto_Partition(array, min, max, size);

	quicksort(array, min, pivot - 1, size);
	quicksort(array, pivot + 1, max, size);
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the Quick sort algorithm. 
 * 
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}