#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of 'array'
 * @array: The array to be sorted
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
    printf("Merging...\n[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);


    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < left_size)
        array[k++] = left[i++];

    while (j < right_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid = size / 2;
    size_t left_size = mid;
    size_t right_size = size - mid;

    int *left = array;
    int *right = array + mid;

    if (size < 2)
	    return;

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    merge(array, left, left_size, right, right_size);
}

