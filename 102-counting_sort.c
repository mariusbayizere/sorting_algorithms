#include "sort.h"

int biggest_value(int *array, int size);
/**
 * counting_sort - Sorts an array of integer the Counting Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Returns:
 *     None (void).
 */
void counting_sort(int *array, size_t size)
{
	int *time, *ptr_sort, polo1, x;

	if (array == NULL || size < 2)
		return;
	ptr_sort = malloc(sizeof(int) * size);
	if (ptr_sort == NULL)
		return;
	polo1 = biggest_value(array, size);
	time = malloc(sizeof(int) * (polo1 + 1));
	if (time == NULL)
	{
		free(ptr_sort);
		return;
	}

	for (x = 0; x < (polo1 + 1); x++)
		time[x] = 0;
	for (x = 0; x < (int)size; x++)
		time[array[x]] += 1;
	for (x = 0; x < (polo1 + 1); x++)
		time[x] += time[x - 1];
	print_array(time, polo1 + 1);

	for (x = 0; x < (int)size; x++)
	{
		ptr_sort[time[array[x]] - 1] = array[x];
		time[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = ptr_sort[x];

	free(ptr_sort);
	free(time);
}
/**
 * biggest_value - Finds the largest value in an integer array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: The largest value in the array.
 */
int biggest_value(int *array, int size)
{
	int x;
	int polo1;

	for (polo1 = array[0], x = 1; x < size; x++)
	{
		if (array[x] > polo1)
			polo1 = array[x];
	}

	return (polo1);
}
