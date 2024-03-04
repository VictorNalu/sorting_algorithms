#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @array: Pointer to the first element of the array
 * @low: Index of the low element in the partition
 * @high: Index of the high element in the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Pointer to the first element of the array
 * @low: Index of the low element in the partition
 * @high: Index of the high element in the partition
 * @size: Size of the array
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	
	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
