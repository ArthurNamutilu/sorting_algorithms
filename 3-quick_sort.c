#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - func swap 2 integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of ints.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, low;

	pivot = array + right;
	for (above = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (above < low)
			{
				swap_ints(array + low, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implements quicksort algo through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of array partition to order.
 * @right: ending index of  array partition to order.
 *
 * Description: Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, p - 1);
		lomuto_sort(array, size, p + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers on ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
