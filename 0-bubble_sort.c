/*
 * File: 0-bubble_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Description: Swaps the values of two integers in an array.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using bubble sort.
 * @array: Pointer to the array of integers to sort.
 * @size: The number of elements in the array.
 *
 * Description: Sorts an array of integers using the bubble sort algorithm and
 * prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (sorted == false)
	{
		sorted = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		len--;
	}
}
