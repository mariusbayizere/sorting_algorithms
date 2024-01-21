#include "sort.h"

void radix_sort(int *array, size_t size);
int beggest_number(int *array, int size);
void sub_sorting_radix(int *array, size_t size, int posi, int *sort);

/**
 * radix_sort - Perform radix sort on an array of integers.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int super, posi, *sort;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	super = beggest_number(array, size);
	for (posi = 1; super / posi > 0; posi *= 10)
	{
		sub_sorting_radix(array, size, posi, sort);
		print_array(array, size);
	}

	free(sort);
}

/**
 * beggest_number - Find the largest integer in an array.
 *
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * Return:
 * The largest integer found in the array.
 */
int beggest_number(int *array, int size)
{
	int super, x;

	for (super = array[0], x = 1; x < size; x++)
	{
		if (array[x] > super)
			super = array[x];
	}

	return (super);
}

/**
 * sub_sorting_radix - Perform radix sort specified of integers array.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * @posi: The position (digit) to consider for sorting.
 * @sort: Pointer to an array to store the sorted result.
 */
void sub_sorting_radix(int *array, size_t size, int posi, int *sort)
{
	int aller[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < size; x++)
		aller[(array[x] / posi) % 10] += 1;

	for (x = 0; x < 10; x++)
		aller[x] += aller[x - 1];

	for (x = size - 1; (int)x >= 0; x--)
	{
		sort[aller[(array[x] / posi) % 10] - 1] = array[x];
		aller[(array[x] / posi) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
		array[x] = sort[x];
}
