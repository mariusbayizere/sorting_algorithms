#include "sort.h"

int pivot_hoare_arr(int *array, size_t size, int back, int next);
void exchange_number(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
void line_sort_one(int *array, size_t size, int back, int next);

/**
 * quick_sort_hoare - Sort an array of integers using Hoare partition scheme.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	line_sort_one(array, size, 0, size - 1);
}

/**
 * exchange_number - Swap the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void exchange_number(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * line_sort_one - Implement a modified version of quicksort array of integers.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * @back: The starting index for the sorting operation.
 * @next: The ending index for the sorting operation.
 * Return: void
 */
void line_sort_one(int *array, size_t size, int back, int next)
{
	int part;

	if (next - back > 0)
	{
		part = pivot_hoare_arr(array, size, back, next);
		line_sort_one(array, size, back, part - 1);
		line_sort_one(array, size, part, next);
	}
}

/**
 * pivot_hoare_arr - Find the pivot element using the Hoare partition scheme.
 *
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 * @back: The starting index for finding the pivot.
 * @next: The ending index for finding the pivot.
 * Return: void
 */
int pivot_hoare_arr(int *array, size_t size, int back, int next)
{
	int jump, adobya, super;

	jump = array[next];
	for (adobya = back - 1, super = next + 1; adobya < super;)
	{
		do {
			adobya++;
		} while (array[adobya] < jump);
		do {
			super--;
		} while (array[super] > jump);

		if (adobya < super)
		{
			exchange_number(array + adobya, array + super);
			print_array(array, size);
		}
	}

	return (adobya);
}
