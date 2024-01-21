#include "sort.h"

void exchange_number(int *a, int *b);
/**
 * shell_sort - Sorts an integer array using the Shell Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Returns:
 *     None (void).
 */
void shell_sort(int *array, size_t size)
{
	size_t dialla;
	size_t x;
	size_t y;

	if (array == NULL || size < 2)
		return;
	for (dialla = 1; dialla < (size / 3);)
		dialla = dialla * 3 + 1;
	for (; dialla >= 1; dialla /= 3)
	{
		for (x = dialla; x < size; x++)
		{
			y = x;
			while (y >= dialla && array[y - dialla] > array[y])
			{
				exchange_number(array + y, array + (y - dialla));
				y -= dialla;
			}
		}
		print_array(array, size);
	}
}
/**
 * exchange_number - swap two integer in Array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void exchange_number(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
