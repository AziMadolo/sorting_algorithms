#include "sort.h"

/**
 * get_max - Find the maximum value in an integer array.
 * @array: The integer array.
 * @size: The size of the array.
 *
 * Return: The maximum value found in the array.
 */
int get_max(int *array, int size)
{
    int max_val = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }

    return max_val;
}

/**
 * counting_sort - Sort an integer array in ascending order using counting sort.
 * @array: The integer array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function does not return anything but sorts the input array.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array, max_val, i;

    if (array == NULL || size < 2)
        return;

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
        return;

    max_val = get_max(array, size);
    count_array = malloc(sizeof(int) * (max_val + 1));
    if (count_array == NULL)
    {
        free(sorted_array);
        return;
    }

    for (i = 0; i < (max_val + 1); i++)
        count_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_array[array[i]] += 1;

    for (i = 1; i < (max_val + 1); i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max_val + 1);

    for (i = (int)size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(count_array);
}

