#include "sort.h"

/**
 * quick_sort - sorts an array of ints using quicksort algo
 * @array: the array to sort
 * @size: size of the array
 * Runs quicky function with 0 as low, size - 1 for high.
 * size - 1 to account for index of an array starting at 0
 * Recursive style is how quicksort is defined on wikipedia,
 * as well as other sites I've found
 */

void quick_sort(int *array, size_t size)
{
	quicky(array, 0, size - 1);
}

/**
 * quicky - recursive function to actually do quicksort
 * @array: the array to sort
 * @low: low point of array, we start at 0
 * @high: high point of array, last index. Full array action
 * calls partion function that does lemuto partition (not the h word)
 * then recursively calls itself, to sort array before pivot
 * and then sort after pivot;
 */
void quicky(int *array, int low, int high)
{
	int pr;

	if (low < high)
	{/* pr PivotReturn is index of pivot, aka partition index */
		pr = partparty(array, low, high);
		quicky(array, low, pr - 1);/* sort before pr */
		quicky(array, pr + 1, high);/* sort after pr */
	}
}

/**
 * partparty - modified lomuto partition scheme.
 * @array: array to be sorted
 * @low: low point of array to be sorted
 * @high: high point of array to be sorted
 * Start from left element & keep track of index of smaller,
 * or equal to, elements as a. While traversing with b, if smaller element,
 * swap current element with array[a]. Print after every swap.
 * Return: index of pivot point
 */
int partparty(int *array, int low, int high)
{
	int a, b, pivot = array[high];
	static int ff, size;
/* FirsttimeFlag is static int, as is size. set at first time partparty ran */
	if (!ff)
	{
		size = high + 1;
		ff++;
	}
	a = b = low;
	while (b < high)
	{
		if (array[b] <= pivot)
		{
			if (a != b)
				swappy(array, &array[b], &array[a], size);
			a++;
		}
		b++;
	}
	if (a != high)
		swappy(array, &array[a], &array[high], size);
	return (a);
}

/**
 * swappy - swaps array values, also prints, cause I wanted one line ifs
 * @array: array to be called for print
 * @left: left array element
 * @right: right array element
 * @size: static size of array, to avoid only printing one side of pivot
 */
void swappy(int *array, int *left, int *right, int size)
{
	int holder = *left;
	*left = *right;
	*right = holder;
	print_array(array, size);
}
