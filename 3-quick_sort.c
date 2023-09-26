#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Perform Lomuto partitioning on a subset of an integer array.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 * @left: Index of the left boundary of the subset.
 * @right: Index of the right boundary of the subset.
 *
 * Return: The final pivot index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        if (array[above] != *pivot)
            print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Recursive implementation of the quicksort algorithm using Lomuto partitioning.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 * @left: Index of the left boundary of the subset.
 * @right: Index of the right boundary of the subset.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int partition;

    if (right - left > 0)
    {
        partition = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, partition - 1);
        lomuto_sort(array, size, partition + 1, right);
    }
}

/**
 * quick_sort - Sort an integer array in ascending order using the quicksort algorithm.
 * @array: Pointer to the integer array.
 * @size: Size of the array.
 *
 * Description: This function uses the Lomuto partition scheme and prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

