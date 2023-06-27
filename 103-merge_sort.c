#include "sort.h"
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src);
void merge_p(size_t l, size_t h, int *arr, int *c);
/**
 * merge_sort - A function that sorts an array using merge
 * @array: The array
 * @size: size of the array
 * Return: Rien
 */
void merge_sort(int *array, size_t size)
{
	size_t f;
	int *b = NULL;

	if (!array || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	if (!b)
		return;
	for (f = 0; f < size; f++)
		b[f] = array[f];
	merge_p(0, size, array, b);
	free(b);
}

/**
 * merge - A function that prints subarrays.
 * @l: index lower
 * @m: index midlle
 * @h: index higher
 * @des: Data destination
 * @s: input data
 * Return: rien
 */
void merge(size_t l, size_t m, size_t h, int *des, int *s)
{
	size_t f = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(s + l, m - l);
	printf("[right]: ");
	print_array(s + m, h - m);
	f = l;
	j = m;
	k = l;
		for (; k < h; k++)
		{
			if (f < m && (j >= h || s[f] <= s[j]))
			{
				des[k] = s[f];
				f++;
			}
			else
			{
				des[k] = s[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(des + l, h - l);
}
/**
 * merge_p - A funtion that separet array
 * @l: index loweer
 * @h: index higher
 * @arr: The array
 * @c: The copy of arry
 * Return: Rien
 */
void merge_p(size_t l, size_t h, int *arr, int *c)
{
	size_t x = 0;

	if (h - l < 2)
		return;
	x = (l + h) / 2;
	merge_p(l, x, arr, c);
	merge_p(x, h, arr, c);
	merge(l, x, h, arr, c);
	for (x = l; x < h; x++)
		c[x] = arr[x];
}
