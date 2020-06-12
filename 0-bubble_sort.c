#include "sort.h"
void swap(int *left, int *right);

/**
 * bubble_sort -sorts an array of integers in ascending order using bubble sort
 * @array: the array to sort
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t oloop, iloop;

	for (oloop = 0; oloop < size - 1; oloop++)
	{
		for (iloop = 0; iloop < size - oloop - 1; iloop++)
		{
			if (array[iloop] > array[iloop + 1])
			{
				swap(&array[iloop], &array[iloop + 1]);
				print_array(array, size);
			}
		}
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
