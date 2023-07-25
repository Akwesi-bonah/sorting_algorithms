#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = 0, j;
	int *aux = NULL, *count = NULL;

	if (array == NULL || size < 2)
		return;

	aux = malloc((size + 1) * sizeof(int));
	if (aux == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		free(aux);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		aux[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = aux[i];
	free(count);
	free(aux);
}
