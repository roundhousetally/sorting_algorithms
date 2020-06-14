#include "sort.h"
void swap(int *left, int *right);
/**
 * selection_sort - sorts an array of ints using selec sort algo
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[temp])
				temp = j;
		}
		swap(&array[temp], &array[i]);
		print_array(array, size);
	}
}

/**
 * swap - swaps values
 * @left: left value
 * @right: right value
 * Return: void
 */
void swap(int *left, int *right)
{
	int holder = *left;
	*left = *right;
	*right = holder;
}
