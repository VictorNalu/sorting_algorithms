#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *output;
	int max, i;
	size_t w, index;
	int *count;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	max = array[0];
	for (w = 1; w < size; w++)
	{
		if (array[w] > max)
			max = array[w];
	}

	/* Create counting array of size (max + 1) and initialize to 0 */
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count occurrences of each element in the original array */
	for (w = 0; w < size; w++)
		count[array[w]]++;

	/* Print the counting array */
	for (i = 0; i <= max; i++)
		printf("%d, ", count[i]);
	printf("\n");

	/* Update the counting array to represent cumulative frequencies */
	for (i = max; i > 0; i--)
		count[i - 1] += count[i];

	/* Update the original array with sorted values */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (w = 0; w < size; w++)
	{
		index = count[array[w]] - 1;
		output[index] = array[w];
		count[array[w]]--;
	}

	/* Copy the sorted array back to the original array */
	for (w = 0; w < size; w++)
		array[w] = output[w];

	/* Free the allocated memory */
	free(count);
	free(output);
}

