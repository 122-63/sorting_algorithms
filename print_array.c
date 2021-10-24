#include "sort.h"
/**
 * print_array - print an array of int
 * @array: is a pointer than array to be printed
 * @size: number of elements in array
 *
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
