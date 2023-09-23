#include "sort.h"
/**
 * swap_ints - It swaps 2 int in an arr.
 * @a: 1st int
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
 * bubble_sort - Sorts integer arrays in ascending order.
 * @array: The array
 * @size: array size
 *
 * Description: Prints  array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t J, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (J = 0; J < len - 1; J++)
		{
			if (array[J] > array[J + 1])
			{
				swap_ints(array + J, array + J + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
