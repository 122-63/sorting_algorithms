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
 * selection_sort - is an array in ascending order
 *                  using sort by selection
 * @array: is an array of integers
 * @size: is the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			min = (array[j] < *min) ? (array + j) : min;
		}
		if ((array + i) != min)
		{
			swap_num(array + i, min);
			print_array(array, size);
		}
	}
}
