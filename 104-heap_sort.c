#include "sort.h"

void heap_sort(int *array, size_t size);
void exchange_number(int *a, int *b);
void binary_heap_tree(int *array, size_t size, size_t fufa, size_t tevel);

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
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		binary_heap_tree(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		exchange_number(array, array + x);
		print_array(array, size);
		binary_heap_tree(array, size, x, 0);
	}
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
 * binary_heap_tree - Construct a binary heap tree from an array.
 *
 * @array: Pointer to the array containing the elements.
 * @size: The number of elements in the array.
 * @fufa: Index of the first element to consider in the.
 * heap construction
 * @tevel: Index of the last element to consider heap construction.
 * Return: void
 */
void binary_heap_tree(int *array, size_t size, size_t fufa, size_t tevel)
{
	size_t back, next, middle;

	back = 2 * tevel + 1;
	next = 2 * tevel + 2;
	middle = tevel;

	if (back < fufa && array[back] > array[middle])
		middle = back;
	if (next < fufa && array[next] > array[middle])
		middle = next;
	if (middle != tevel)
	{
		exchange_number(array + tevel, array + middle);
		print_array(array, size);
		binary_heap_tree(array, size, fufa, middle);
	}
}
