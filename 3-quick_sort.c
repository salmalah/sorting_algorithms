#include "sort.h"

/**
* swaper - swap
* @arr: array
* @i: index
* @j: index
**/
void swaper(int *arr, size_t i, size_t j)
{
	int tmp = arr[i];

	arr[i] = arr[j];
	arr[j] = tmp;
}
/**
 * partition - selection----
 * @arr: arg
 * @low: arg
 * @high: arg
 * @size: size
 * Return: int
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swaper(arr, i, j);
			if (i != j)
				print_array(arr, size);
		}
	}
	swaper(arr, i + 1, high);
	print_array(arr, size);
	return (i + 1);
}

/**
* q_sort_helper - recursive quick sort
* @array: array to sort
* @low: l----
* @high: ------
* @size: size
**/
void q_sort_helper(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high, size);
		q_sort_helper(arr, low, pivot - 1, size);
		q_sort_helper(arr, pivot + 1, high, size);
	}
}

/**
 * quick_sort - quick sort
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	q_sort_helper(array, 0, size - 1, size);
}
