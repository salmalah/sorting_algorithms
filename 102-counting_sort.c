#include "sort.h"
/**
  * counting_sort - A function that sorts an array using counting algorithm
  * @array: The array
  * @size: size of the array.
  * Return: Rien
  */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *n = NULL, m = 0, j = 0;

	if (!array || size < 2)
		return;
	m = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}
	n = malloc(sizeof(int) * (m + 1));
	if (!n)
		return;
	for (j = 0; j <= m; j++)
		n[j] = 0;
	for (i = 0; i < size; i++)
		n[array[i]] += 1;
	for (j = 0; j < m; j++)
	{
		n[j + 1] += n[j];
		printf("%d, ", n[j]);
	}
	n[j + 1] += n[j];
	printf("%d\n", n[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = n[array[i]] - 1;
		if (array[i] != array[j])
		{
			m = array[i];
			array[i] = array[j];
			array[j] = m;
		}
	}
	free(n);
}
