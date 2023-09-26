#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending order using the
 *              shell sort algorithm with the Knuth interval sequence.
 * @array: Pointer to an array of integers.
 * @size: Size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the shell sort algorithm with the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;

    if (array == NULL || size < 2)
        return;

    for (gap = 1; gap < size / 3;)
        gap = gap * 3 + 1;

    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            j = i;
            while (j >= gap && array[j - gap] > array[j])
            {
                swap(array + j, array + (j - gap));
                j -= gap;
            }
        }
        print_array(array, size);
    }
}

