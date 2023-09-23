#include "sort.h"

/**
 * swap_ints - func that swaps 2 ints in an arr
 * @a: 1st int to swap.
 * @b: 2nd int to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - func sorts an array of integers in ascending
 *              _order using the shell sort algorithm.
 * @array: array of ints
 * @size: size of  array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	/* gp == gap*/
	size_t gp, a, b;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (a = gp; a < size; a++)
		{
			b = a;
			while (b >= gp && array[b - gp] > array[b])
			{
				swap_ints(array + b, array + (b - gp));
				b -= gp;
			}
		}
		print_array(array, size);
	}
}
