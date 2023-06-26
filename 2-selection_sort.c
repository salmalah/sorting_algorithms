#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int t;
	size_t k, j, min_num;

	if (!array || size < 2)
		return;
	for (k = 0; k < size - 1; k++)
	{
		min_num = k;
		for (j = k + 1; j < size; j++)
		{
			if (array[j] < array[min_num])
				min_num = j;
		}
		if (min_num != k)
		{
			t = array[k];
			array[k] = array[min_num];
			array[min_num] = t;
			print_array(array, size);
		}
	}
}
