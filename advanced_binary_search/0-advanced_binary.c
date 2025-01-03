#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the array being searched
 * @array: Pointer to the first element of the array
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursive function for advanced binary search
 * @array: Pointer to the first element of the array
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of the value, or -1
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);
	mid = left + (right - left) / 2;

	if (array[mid] == value &&
	    (mid == left || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (advanced_binary_recursive(array, left, mid, value));

	return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using advanced binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of the value, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
