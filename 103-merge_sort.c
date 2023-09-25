#include "sort.h"
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Function that sorts a subarray of integers.
 * @subarr: subarray of ints to sort.
 * @buff: buffer (stores sorted subarray)
 * @front: array front index
 * @mid: array middle index
 * @back: array back index.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - merge sort algorithm through recursion
 * @subarr:  subarray of an array of integers to sort
 * @buff:  buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t md;

	if (back - front > 1)
	{
		md = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, md);
		merge_sort_recursive(subarr, buff, md, back);
		merge_subarr(subarr, buff, front, md, back);
	}
}

/**
 * merge_sort - Sort int arr in ascending  merge sort algorithm.
 * @array: An array of integers.
 * @size: array size
 *
 * Description: This Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *bff;

	if (array == NULL || size < 2)
		return;

	bff = malloc(sizeof(int) * size);
	if (bff == NULL)
		return;

	merge_sort_recursive(array, bff, 0, size);
	free(bff);
}
