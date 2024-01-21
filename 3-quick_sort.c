#include "sort.h"

void exchange_number(int *a, int *b);
int raid_array_element(int *array, size_t size, int left, int right);
void SortList_element(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * raid_array_element - Searches for an element in a range of an integer array.
 *
 * @array: Pointer to the first element of array.
 * @size: Number of elements in the array.
 * @left: The starting index of the range to search.
 * @right: The ending index of the range to search.
 *
 * Return: The index of the found element, or -1 if the element is not found.
 */
int raid_array_element(int *array, size_t size, int left, int right)
{
	int *vast, levela, below;

	vast = array + right;
	for (levela = below = left; below < right; below++)
	{
		if (array[below] < *vast)
		{
			if (levela < below)
			{
				exchange_number(array + below, array + levela);
				print_array(array, size);
			}
			levela++;
		}
	}

	if (array[levela] > *vast)
	{
		exchange_number(array + levela, vast);
		print_array(array, size);
	}

	return (levela);
}

/**
 * exchange_number - Swap two integers in an array.
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

/**
 * quick_sort - Sorts integer array using the Quick Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Returns
 *     None (void).
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	SortList_element(array, size, 0, size - 1);
}

/**
 * SortList_element - Sorts a range of element integer
 * array custom sorting algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @left: The starting index of the range to sort.
 * @right: The ending index of the range to sort.
 * Returns:
 *     None (void).
 */
void SortList_element(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = raid_array_element(array, size, left, right);
		SortList_element(array, size, left, part - 1);
		SortList_element(array, size, part + 1, right);
	}
}
