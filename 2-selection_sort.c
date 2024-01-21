#include "sort.h"

void exchange_number(int *a, int *b);
/**
 * selection_sort - Sorts an array of integer Selection Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Returns:
 *     None (void).
 */
void selection_sort(int *array, size_t size)
{
	int *corte;
	size_t x, y;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		corte = array + x;
		for (y = x + 1; y < size; y++)
			corte = (array[y] < *corte) ? (array + y) : corte;
		if ((array + x) != corte)
		{
			exchange_number(array + x, corte);
			print_array(array, size);
		}
	}
}
/**
 * exchange_number - Swap the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Returns:
 *     None (void).
 */
void exchange_number(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
