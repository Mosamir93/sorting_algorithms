#include "sort.h"

/**
 * heap_sort - Heap Sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
    int start_idx, i, j;

    if (array == NULL || size <=   1)
        return;

    start_idx = ((int)size /   2) -   1;
    i = start_idx;
    while (i >=   0)
    {
        heapify(array, (int)size, i, size);
        i--;
    }

    j = (int)size -   1;
    while (j >=   0)
    {
        if (j !=   0)
        {
            swap_heap(&array[j], &array[0]);
            print_array(array, size);
            heapify(array, j,   0, size);
        }
        j--;
    }
}

/**
 * swap_heap - Swap two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: nothing
 */
void swap_heap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * find_max - Find the index of the largest element among the children of a node.
 * @array: The array to be sorted.
 * @n: The size of the current subtree.
 * @i: The index of the node.
 *
 * Return: The index of the largest element among the children of the node at index i.
 */
int find_max(int *array, int n, int i)
{
    int left =  2 * i +  1;
    int right =  2 * i +  2;
    int largest = i;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;

    return largest;
}
/**
 * heapify - Heapify the subtree rooted at index i.
 * @array: The array to be sorted.
 * @n: The size of the current subtree.
 * @i: The index of the node to be heapified.
 * @size: The total size of the array.
 * 
 * This function ensures that the subtree rooted at index i is a max heap.
 */
void heapify(int *array, int n, int i, size_t size)
{
    int largest = find_max(array, n, i);

    if (i != largest)
    {
        swap_heap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, n, largest, size);
    }
}
