#include "sort.h"
/**
* swaper - Function swaps two numbers
* @li: in array
* @m: first index
* @k: second index
* Return: Nothing
**/
void s_wap(int *li, size_t m, size_t k)
{
	int t = li[m];

	li[m] = li[k];
	li[k] = t;
}
/**
 * p - Array partition
 *
 * @li:  in array
 * @s: the start index
 * @e: ending index
 * @sz: The size
 * Return: in Integer
 */
int p(int *li, int s, int e, size_t sz)
{
	int pp = li[e], k = s - 1, j;

	for (j = s; j <= e - 1; j++)
	{
		if (li[j] < pp)
		{
			k++;
			s_wap(li, k, j);
			if (k != j)
				print_array(li, sz);
		}
	}
	s_wap(li, k + 1, e);
	print_array(li, sz);

	return (k + 1);
}

/**
* q_sort - Function recursive
* @li: array
* @s: start index
* @e: ending index
* @sz: size of array
* Return: Nothing
**/
void q_sort(int *li, int s, int e, size_t sz)
{
	int pp;

	if (s < e)
	{
		pp = p(li, s, e, sz);
		q_sort(li, s, pp - 1, sz);
		q_sort(li, pp + 1, e, sz);
	}
}

/**
 * quick_sort - Sorts an array of integers
 * @array: Array pointer
 * @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
