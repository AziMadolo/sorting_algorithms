#include "sort.h"

void exchange_elements(int *first, int *second);
void establish_max_heap(int *array, size_t size, size_t base, size_t root);
void perform_heap_sort(int *array, size_t size);

/**
 * exchange_elements - Swap two integers within an array.
 * @first: Pointer to the first integer.
 * @second: Pointer to the second integer.
 */
void exchange_elements(int *first, int *second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * establish_max_heap - Convert a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void establish_max_heap(int *array, size_t size, size_t base, size_t root)
{
    size_t left, right, largest;

    left = 2 * root + 1;
    right = 2 * root + 2;
    largest = root;

    if (left < base && array[left] > array[largest])
        largest = left;
    if (right < base && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        exchange_elements(array + root, array + largest);
        print_array(array, size);
        establish_max_heap(array, size, base, largest);
    }
}

/**
 * perform_heap_sort - Sort an array of integers in ascending order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm. Prints the array after each swap.
 */
void perform_heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = (size / 2) - 1; i >= 0; i--)
        establish_max_heap(array, size, size, i);

    for (i = size - 1; i > 0; i--)
    {
        exchange_elements(array, array + i);
        print_array(array, size);
        establish_max_heap(array, size, i, 0);
    }
}

