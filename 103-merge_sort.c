#include "sort.h"

/**
 * merge_subarr - Merge two subarrays into a sorted subarray.
 * @array: The array containing the subarrays.
 * @buff: A buffer to store the sorted subarray.
 * @front: The starting index of the first subarray.
 * @mid: The ending index of the first subarray.
 * @back: The ending index of the second subarray.
 */
void merge_subarr(int *array, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);

	printf("[right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		buff[k++] = array[i];
	for (; j < back; j++)
		buff[k++] = array[j];
	for (i = front, k = 0; i < back; i++)
		array[i] = buff[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm recursively.
 * @array: The array to sort.
 * @buff: A buffer to store intermediate results.
 * @front: The starting index of the subarray.
 * @back: The ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(array, buff, front, mid);
		merge_sort_recursive(array, buff, mid, back);
		merge_subarr(array, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using merge sort.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

