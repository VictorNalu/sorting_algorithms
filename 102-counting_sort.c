#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max;
	size_t w;
	int *count;
	int i;
	int *output;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (w = 1; w < size; ++w)
	{
		if (array[w] > max)
			max = array[w];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (w = 0; w < size; ++w)
		count[array[w]]++;

	for (i = 1; i <= max; ++i)
		count[i] += count[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL) {
		free(count);
		return;
	}

	for (w = 0; w < size; ++w)
	{
		output[count[array[w]] - 1] = array[w];
		count[array[w]]--;
	}

	for (w = 0; w < size; ++w)
		array[w] = output[w];

	for (i = 0; i <= max; ++i)
		printf("%d, ", count[i]);
	printf("\n");

	free(count);
	free(output);
}
