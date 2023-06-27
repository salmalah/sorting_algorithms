#include "sort.h"
/**
 * shell_sort - A function sorts integers in ascending order using Shell sort
 * @array: The array
 * @size:size of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int n;
	size_t g, k, m;

	g = 1;
	if (size < 2 || !array)
		return;
	while (g < size)
		g = g * 3 + 1;
	g = (g - 1) / 3;
	while (g > 0)
	{
		for (k = g; k < size; k++)
		{
			n = array[k];
			for (m = k; m >= g && array[m - g] > n; m -= g)
			{
				array[m] = array[m - g];
			}
			array[m] = n;
		}
		print_array(array, size);

		g = (g - 1) / 3;
	}
}

