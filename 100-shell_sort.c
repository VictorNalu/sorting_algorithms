#include "sort.h"
#include <stdio.h>

/**
* shell_sort - function using Knuth sequence
* integers in ascending order
* @array: Array to be sorted
* @size: number of elements in the array
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	/* Find the maximum interval (Knuth sequence: 1, 4, 13, 40, 121, ...)*/
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	/* Start with the largest interval, then reduce the interval */
	while (interval > 0)
	{
		/* Perform insertion sort with the current interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}

		/* Print the array after each interval decrease*/
		print_array(array, size);

		/* Decrease the interval for the next loop*/
		interval = (interval - 1) / 3;
	}
}
