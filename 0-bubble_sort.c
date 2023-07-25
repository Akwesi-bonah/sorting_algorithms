#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	int var, flag;

	if (array == NULL || size < 2)
		return;
	len = size - 1;
	while (flag)
	{
		flag = 0;
		for (i = 0; i < len; i++)
		{
			if (array[i] > array[i + 1])
			{
				flag = 1;
				var = array[i];
				array[i] = array[i + 1];
				array[i + 1] = var;
				print_array(array, size);
			}
		}
	}
}
