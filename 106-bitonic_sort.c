
#include "sort.h"

void exchenge_number(int *a, int *b);
void automic_sort(int *array, size_t size, size_t facter, size_t cana,
		char bwan);
void sequatinal_sorting_bitomic(int *array, size_t size, size_t facter,
		size_t cana, char bwan);
void bitonic_sort(int *array, size_t size);

/**
 * automic_sort - Perform atomic sorting on an array of integers.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * @facter: The factor for atomic sequence generation.
 * @cana: The number of elements in each atomic sequence.
 * @bwan: A character parameter used for sorting direction.
 * Return: void
 */
void automic_sort(int *array, size_t size, size_t facter, size_t cana,
		char bwan)
{
	size_t man;
	size_t x;

	man = cana / 2;
	if (cana > 1)
	{
		for (x = facter; x < facter + man; x++)
		{
			if ((bwan == UP && array[x] > array[x + man]) ||
			    (bwan == DOWN && array[x] < array[x + man]))
				exchenge_number(array + x, array + x + man);
		}
		automic_sort(array, size, facter, man, bwan);
		automic_sort(array, size, facter + man, man, bwan);
	}
}

/**
 * bitonic_sort - Perform bitonic sorting on an array of integers.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sequatinal_sorting_bitomic(array, size, 0, size, UP);
}

/**
 * sequatinal_sorting_bitomic - Perform sequential bitonic sorting array.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 * @facter: The factor for bitonic sequence generation.
 * @cana: The number of elements in each bitonic sequence.
 * @bwan: A character parameter used for sorting direction.
 * Return: void
 */
void sequatinal_sorting_bitomic(int *array, size_t size, size_t facter,
		size_t cana, char bwan)
{
	size_t cut = cana / 2;
	char *xxx = (bwan == UP) ? "UP" : "DOWN";

	if (cana > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", cana, size, xxx);
		print_array(array + facter, cana);

		sequatinal_sorting_bitomic(array, size, facter, cut, UP);
		sequatinal_sorting_bitomic(array, size, facter + cut, cut, DOWN);
		automic_sort(array, size, facter, cana, bwan);

		printf("Result [%lu/%lu] (%s):\n", cana, size, xxx);
		print_array(array + facter, cana);
	}
}

/**
 * exchenge_number - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * Return: void
 */
void exchenge_number(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
