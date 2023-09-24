#include "sort.h"
/**
 * get_max - func that gets the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Array size
 *
 * Return: maximum integer
 */
int get_max(int *array, int size)
{
	int mx, j;

	for (mx = array[0], j = 1; j < size; j++)
	{
		if (array[j] > mx)
			mx = array[j];
	}

	return (mx);
}

/**
 * counting_sort - Sort an integer arrays in ascending order
 *                 by using the counting sort algorithm.
 * @array: integer array
 * @size: array size
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, mx, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	mx = get_max(array, size);
	count = malloc(sizeof(int) * (mx + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (mx + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (mx + 1); j++)
		count[j] += count[j - 1];
	print_array(count, mx + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count);
}
