#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints array of integers
 *
 * @array: array to be print
 * @size: no of elements in arr
 */
void print_array(const int *array, size_t size)
{
	size_t j;

	j = 0;
	while (array && j < size)
	{
		if (j > 0)
			printf(", ");
		printf("%d", array[j]);
		++j;
	}
	printf("\n");
}
