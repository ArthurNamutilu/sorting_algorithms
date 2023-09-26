#include "sort.h"

int get_mx(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *bff);
void radix_sort(int *array, size_t size);

/**
 * get_mx - func that gets the mx value in int array
 * @array: int array
 * @size: arr size
 *
 * Return: The mximum integer in the array.
 */
int get_mx(int *array, int size)
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
 * radix_counting_sort - Sorts significant dgts of int array
 *                       in ascending order using the counting sort algorithm.
 * @array: int array
 * @size: arr size
 * @sig: Significant digit to sort on.
 * @bff: A bffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *bff)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t j;

    for (j = 0; j < size; j++)
        count[(array[j] / sig) % 10] += 1;

    for (j = 0; j < 10; j++)
        count[j] += count[j - 1];

    for (j = size - 1; (int)j >= 0; j--)
    {
        bff[count[(array[j] / sig) % 10] - 1] = array[j];
        count[(array[j] / sig) % 10] -= 1;
    }

    for (j = 0; j < size; j++)
        array[j] = bff[j];
}

/**
 * radix_sort - Sorts int array in ascending order using the radix sort algothm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int mx, sig, *bff;

    if (array == NULL || size < 2)
        return;

    bff = malloc(sizeof(int) * size);
    if (bff == NULL)
        return;

    mx = get_mx(array, size);
    for (sig = 1; mx / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, bff);
        print_array(array, size);
    }

    free(bff);
}
