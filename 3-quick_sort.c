#include "sort.h"
#include <sys/types.h>
/**
 * partition - divides the array and swap datas
 * @array: array of integers
 * @lo: bottom limit
 * @hi: upper limit
 * @size: size of the array
 * Return: new index
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot = array[hi], swap;
	ssize_t i = lo - 1, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[j];
				array[j] = array[i];
				array[i] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quicksort - divides the array to perform the sorting
 * sort method
 * @array: array to be sorted
 * @lo: bottom limit
 * @hi: upper limit
 * @size: array's size
 * Return: nothing
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - perform an incremental sorting using Lomuto
 * sort method
 * @array: array to be sorted
 * @size: array's size
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
