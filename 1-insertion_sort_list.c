#include "sort.h"

/**
 *
 * SortedList
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *nextnode = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->prev = current->next = NULL;
		sortedInsert(&sorted, current);
		current = next;
	}
	*list = sorted;
}
