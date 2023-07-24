#include "sort.h"
/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort
 * algorithm
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, c;
	int aux;

	for (i = 0; i < size; i++)
	{
		c = i;
		for (j = i + 1; j < size; j++)
			if (array[c] > array[j])
				c = j;
		if (i != c)
		{
			aux = array[i];
			array[i] = array[c];
			array[c] = aux;
			print_array(array, size);
		}
	}
}
