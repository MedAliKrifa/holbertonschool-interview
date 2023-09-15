#include "sort.h"

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        array[k++] = left[i++];
    }

    while (j < right_size)
    {
        array[k++] = right[j++];
    }
}

void merge_sort(int *array, size_t size)
{
    if (size <= 1)
    {
        return; // Base case: Array is already sorted
    }

    size_t mid = size / 2;

    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    if (!left || !right)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Divide the array into two sub-arrays
    for (size_t i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }

    for (size_t i = mid; i < size; i++)
    {
        right[i - mid] = array[i];
    }

    // Recursively sort the sub-arrays
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted sub-arrays back into the original array
    merge(array, left, mid, right, size - mid);

    free(left);
    free(right);
}
