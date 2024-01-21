#include "sort.h"

void merge_sort(int *array, size_t size);
void replicate_sub_sort(int *xbar, int *buff, size_t front, size_t black);
void sub_sort(int *xbar, int *buff, size_t front, size_t mid,
		size_t black);

/**
 * replicate_sub_sort - Replicate and sort a subarray of integer.
 *
 * @xbar: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @black: The back index of the subarray.
 * Return: void
 */
void replicate_sub_sort(int *xbar, int *buff, size_t front, size_t black)
{
	size_t angola;

	if (black - front > 1)
	{
		angola = front + (black - front) / 2;
		replicate_sub_sort(xbar, buff, front, angola);
		replicate_sub_sort(xbar, buff, angola, black);
		sub_sort(xbar, buff, front, angola, black);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending.
 * order using the merge sort algorithm
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *stock;

	if (array == NULL || size < 2)
		return;

	stock = malloc(sizeof(int) * size);
	if (stock == NULL)
		return;

	replicate_sub_sort(array, stock, 0, size);

	free(stock);
}

/**
 * sub_sort - Sort a subarray of integers.
 *
 * @xbar: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @mid: The middle index of the subarray.
 * @front: The front index of the subarray.
 * @black: The back index of the subarray.
 * Return: void
 */
void sub_sort(int *xbar, int *buff, size_t front, size_t mid,
		size_t black)
{
	size_t x, y, p = 0;

	printf("Merging...\n[left]: ");
	print_array(xbar + front, mid - front);

	printf("[right]: ");
	print_array(xbar + mid, black - mid);

	for (x = front, y = mid; x < mid && y < black; p++)
		buff[p] = (xbar[x] < xbar[y]) ? xbar[x++] : xbar[y++];
	for (; x < mid; x++)
		buff[p++] = xbar[x];
	for (; y < black; y++)
		buff[p++] = xbar[y];
	for (x = front, p = 0; x < black; x++)
		xbar[x] = buff[p++];

	printf("[Done]: ");
	print_array(xbar + front, black - front);
}
