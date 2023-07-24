#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, l;
	int a, f;

	if (array == NULL || size < 2)
		return;
	l = size - 1;
	while (f)
	{
		f = 0;
		for (i = 0; i < l; i++)
		{
			if (array[i] > array[i + 1])
			{
				f = 1;
				a = array[i];
				array[i] = array[i + 1];
				array[i + 1] = a;
				print_array(array, size);
			}
		}
	}
}
