#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b);

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Sorts the array and prints it before and after sorting.
 */
void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
            min = (array[j] < *min) ? (array + j) : min;

        if ((array + i) != min)
        {
            swap_integers(array + i, min);
            print_array(array, size);
        }
    }
}

