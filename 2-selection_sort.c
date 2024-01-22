#include "sort.h"

/**
 * selection_sort - sorts an array based on selection sort algorithm
 * @array: array to sort
 * @size: size of the array to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
