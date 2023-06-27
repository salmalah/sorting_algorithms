#include "sort.h"

/**
 * m_ax - A function give max value in an array
 * @arr: The array
 * @n: size of the array
 *
 * Return: The maximum integer in the array.
 */
int m_ax(int *arr, int n)
{
	int m, i;

	for (m = arr[0], i = 1; i < n; i++)
	{
		if (arr[i] > m)
			m = arr[i];
	}
	return (m);
}
/**
 * counting_sort - A fucntion Sort an array of integers in ascending order
 * @array: An array
 * @size:size of the array.
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *n, *sort, max, i;

	if (!array || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (!sort)
		return;
	max = m_ax(array, size);
	n = malloc(sizeof(int) * (max + 1));
	if (!n)
	{
		free(sort);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		n[i] = 0;
	for (i = 0; i < (int)size; i++)
		n[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		n[i] += n[i - 1];
	print_array(n, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sort[n[array[i]] - 1] = array[i];
		n[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = sort[i];
	}
	free(sort);
	free(n);
}
