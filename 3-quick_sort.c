#include "sort.h"
/**
 * swap_num - swap 2 numbers in an array
 * @a: first number to change
 * @b: second number to change
 */
void swap_num(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partt - Sort an array of integers with lomuto partition
 * @array: is the array of integers
 * @size: The size of the array
 * @left: Is the index of the subset to sort
 * @right: is the final index of the subset to sort
 *
 * Return: Is the final index of the partition
 */
int lomuto_partt(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_num(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_num(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - fast sorting by recursion
 * @array: is the array of integers to sort
 * @size: is the array of integers to sort
 * @left: Is the starting index of the array partition to sort
 * @right: The final index of the partition of the array to sort
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partt(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}
/**
 * quick_sort -  is an array of integers to sort in ascending
 *               order using quicksort
 * @array: is an array of integers
 * @size: is the size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, size, 0, size - 1);
}
