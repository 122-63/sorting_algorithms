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
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of number to sort
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
	{
		return;
	}
	
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_num(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
