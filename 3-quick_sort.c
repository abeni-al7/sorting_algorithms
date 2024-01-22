#include "sort.h"

/**
 * quick_sort - sorts an array of integers using the quicksort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}

/**
 * qs - recursive function for quicksort algorithm
 * @array: array of integers to be sorted
 * @left: leftmost index of partition
 * @right: rightmost index of partition
 * @size: size of the array
 */

void qs(int *array, int left, int right, size_t size)
{
	int p;

	if (left >= right)
		return;

	p = partition(array, left, right, size);
	qs(array, left, p - 1, size);
	qs(array, p + 1, right, size);
}

/**
 * partition - partitions an array for quicksort algorithm
 * @array: array to be partitioned
 * @left: leftmost index of partition
 * @right: rightmost index of partition
 * @size: size of the array
 * Return: index of the pivot
 */

int partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i, j, temp;

	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
