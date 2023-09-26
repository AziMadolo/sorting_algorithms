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
 * bitonic_merge - Sort a bitonic sequence within an array of integers.
 * @array: Array of integers to be sorted.
 * @size: The size of the array.
 * @start: Index of the starting point for the sequence to sort.
 * @seq: Size of the sequence to sort.
 * @flow: The sorting direction ('UP' or 'DOWN').
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == 'U' && array[i] > array[i + jump]) ||
                (flow == 'D' && array[i] < array[i + jump]))
                swap_ints(array + i, array + i + jump);
        }
        bitonic_merge(array, size, start, jump, flow);
        bitonic_merge(array, size, start + jump, jump, flow);
    }
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the building bitonic sequence block.
 * @seq: Size of the building bitonic sequence block.
 * @flow: The direction for sorting the bitonic sequence block.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    char *str = (flow == 'U') ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);

        bitonic_seq(array, size, start, cut, 'U');
        bitonic_seq(array, size, start + cut, cut, 'D');
        bitonic_merge(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the bitonic sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Prints the array before and after sorting.
 * Works only for size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    printf("Initial array:\n");
    print_array(array, size);

    bitonic_seq(array, size, 0, size, 'U');

    printf("\nSorted array:\n");
    print_array(array, size);
}

