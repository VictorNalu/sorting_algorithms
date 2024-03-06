#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array[].
 * @array: Pointer to the original array.
 * @left: Index of the left subarray.
 * @middle: Index of the middle element.
 * @right: Index of the right subarray.
 * @tmp: Temporary array to store the merged result.
 */
void merge(int *array, size_t left, size_t middle, size_t right, int *tmp)
{
	size_t i = left, j = middle + 1, k = 0;

	while (i <= middle && j <= right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i <= middle)
		tmp[k++] = array[i++];
	while (j <= right)
		tmp[k++] = array[j++];

	for (i = 0; i < k; i++)
		array[left + i] = tmp[i];
}

/**
 * merge_sort_recursive - Recursively sorts an array using
 * - the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @left: Index of the left boundary.
 * @right: Index of the right boundary.
 * @tmp: Temporary array to store merged result.
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *tmp)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		merge_sort_recursive(array, left, middle, tmp);
		merge_sort_recursive(array, middle + 1, right, tmp);
		merge(array, left, middle, right, tmp);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;

	merge_sort_recursive(array, 0, size - 1, tmp);

	free(tmp);
}
