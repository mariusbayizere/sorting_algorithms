#include "sort.h"

/**
 * exchange_number - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Returns:
 *   None (void).
 */
void exchange_number(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Returns:
 *   None (void).
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, n = size;
	bool flog = false;

	if (array == NULL || size < 2)
		return;

	while (flog == false)
	{
		flog = true;
		for (x = 0; x < n - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				exchange_number(array + x, array + x + 1);
				print_array(array, size);
				flog = false;
			}
		}
		n--;
	}
}
