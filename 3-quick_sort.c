#include "sort.h"
void quick_s(int *array, int s, int e, size_t size);
/**
 * quick_sort - function that sorts an array of integers
 *
 * @array: In array
 * @size: size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - Fucntion partition
 * @arr:  In array
 * @s: starting index
 * @e: ending index
 * @size: size of arrau
 * Return: in integer
 */
int partition(int *arr, int s, int e, size_t size)
{
	int k = s - 1, j = s, a = 0, pivot;

	pivot = arr[e];

	for (; j < e; j++)
	{
		if (arr[j] < pivot)
		{
			k++;
			if (arr[k] != arr[j])
			{
				a = arr[k];
				arr[k] = arr[j];
				arr[j] = a;
				print_array(arr, size);
			}
		}
	}
	if (arr[k + 1] != arr[e])
	{
		a = arr[k + 1];
		arr[k + 1] = arr[e];
		arr[e] = a;
		print_array(arr, size);
	}

	return (k + 1);
}

/**
 * quick_s - Function recursive
 * @array: an given array
 * @s: starting index
 * @e: ending index
 * @size: array's size
 * Return: rien
 */
void quick_s(int *array, int s, int e, size_t size)
{
	int p;

	if (s < e)
	{
		p = partition(array, s, e, size);
		quick_s(array, s, p - 1, size);
		quick_s(array, p + 1, e, size);
	}
}
