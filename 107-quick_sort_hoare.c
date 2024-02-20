#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@a: array element
*@b: array element
*/
void swap(int *array, size_t a, size_t b)
{
    int tmp;

    tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
    int current = first -  1, finder = last +  1;
    int pivot = array[last];

    while (1)
    {
        current++;
        while (array[current] < pivot)
        {
            current++;
        }
        finder--;
        while (array[finder] > pivot)
        {
            finder--;
        }
        if (current >= finder)
            return (current);
        swap(array, current, finder);
        print_array(array, size);
    }
}

/**
 *_quicksort - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void _quicksort(int *array, size_t first, size_t last, int size)
{
    size_t position =  0;

    if (first < last)
    {
        position = hoare_partition(array, first, last, size);
        _quicksort(array, first, position -  1, size);
        _quicksort(array, position, last, size);
    }
}

/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array of numbers
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_quicksort(array, 0, size - 1, size);
}
