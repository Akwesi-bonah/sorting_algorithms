#include "sort.h"
/**
 * shell_sort - function that sort an array
 * sort is done in ascending order using
 * shell sort algorithm
 * @array: array of intgers
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && arry[j - gap] > temp; j -= gap)
				array[i] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
