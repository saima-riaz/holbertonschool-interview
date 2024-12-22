#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Perform sift-down operation to maintain the max-heap property.
 * @array: The array of integers.
 * @size: The size of the array.
 * @root: The root index of the heap.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left <= end && array[left] > array[largest])
        largest = left;

    if (right <= end && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size); /* Print array after swap */
        sift_down(array, size, largest, end);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build the max heap */
    for (ssize_t i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);

    /* Extract elements from the heap */
    for (size_t end = size - 1; end > 0; end--)
    {
        swap(&array[0], &array[end]);
        print_array(array, size); /* Print array after swap */
        sift_down(array, size, 0, end - 1);
    }
}
