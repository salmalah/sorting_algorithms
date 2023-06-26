#include "sort.h"
/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: Array pointer
 * @size: number of elements in array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t k, m;

	if (!array || size < 2)
		return;
	for (m = 0; m < size - 1; m++)
	{
		for (k = 0; k < size - m - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}


