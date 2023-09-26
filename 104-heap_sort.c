#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Func swaps 2 ints in an arr.
 * @a: 1st int
 * @b: 2nd int
 */
void swap_ints(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

/**
 * max_heapify - Turns binary tree into complete binary heap ettte
 * @array: int arr rep binary tree
 * @size: arr size
 * @base: index row of tree.
 * @root: binary tree root node
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
    size_t l, r, lrg;

    l = 2 * root + 1;
    r = 2 * root + 2;
    lrg = root;

    if (l < base && array[l] > array[lrg])
        lrg = l;
    if (r < base && array[r] > array[lrg])
        lrg = r;

    if (lrg != root)
    {
        swap_ints(array + root, array + lrg);
        print_array(array, size);
        max_heapify(array, size, base, lrg);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    int j;

    if (array == NULL || size < 2)
        return;

    for (j = (size / 2) - 1; j >= 0; j--)
        max_heapify(array, size, size, j);

    for (j = size - 1; j > 0; j--)
    {
        swap_ints(array, array + j);
        print_array(array, size);
        max_heapify(array, size, j, 0);
    }
}
