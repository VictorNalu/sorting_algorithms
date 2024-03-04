#include "sort.h"
/**
* bubble_sort - Sorts an array of integers in ascending
* order using Bubble sort.
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void bubble_sort(int *array, size_t size)
{

	size_t v, p;
	int tmp;

	if (size < 2)
		return;

	for (v = 0; v < size; v++)
	{
		for (p = 0; p < size - v - 1; p++)
		{
			if (array[p] > array[p + 1])
			{
			tmp = array[p];
			array[p] = array[p + 1];
			array[p + 1] = tmp;
			print_array(array, size);
			}
		}
	}
}
