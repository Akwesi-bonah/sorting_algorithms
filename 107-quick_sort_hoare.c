#include "sort.h"
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
	int pivot = array[lo], swap;
	ssize_t i = lo - 1, j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		swap = array[j];
		array[j] = array[i];
		array[i] = swap;
		print_array(array, size);
	}
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
		quicksort(array, lo, p, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - perform an incremental sorting using Hoare
 * sort method
 * @array: array to be sorted
 * @size: array's size
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
