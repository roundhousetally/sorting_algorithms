#include "sort.h"

/**
 * insertion_sort_list - Sorts in ascending ordedr using insertion sort.
 * @list: doubly linked list to be sorted.
 * Outerloop increments through list, while inner while loop (hah)
 * increments from current index of oloop backwards using trav(erse).
 * pt(PriorTrav) stays prior to trav, so it's our comparison node to trav.
 * In inner loop, we first set flag. If flag stays same, we increment trav
 * to previous, and start loop again. If comparison for swap is valid, we do:
 * 1. Set TeMP to previous of pt. If it's a node, we point it's next to trav.
 * 2. Set pt's next to trav's next, then pt's prev to trav itself. Pt is done.
 * 3. Check if node after trav. If so, set that node's prev to pt.
 * 4. Trav finish up, with trav's next to pt.
 * 5. Set flag to redo this index of inner loop, by skipping trav = trav->next
 * 6. print list for each swap, so right after swap is done.
 */
void insertion_sort_list(listint_t **list)
{/*pt is essentially left, trav is right from old attempt */
	listint_t *trav, *tmp, *oloop, *pt;
	int flippy;/* "if flippy" is more fun to say than "if flag" */

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;/* also checks next, no point sorting single node */
	oloop = *list, oloop = oloop->next;/* start loop at index 1 of list */
	while (oloop != NULL)
	{
		trav = oloop;
		pt = trav->prev;
		while (trav->prev != NULL)/* inner loop for backwards increment of trav*/
		{/* trav will travel backwards until head of list */
			flippy = 1;
			if (pt->n > trav->n)
			{
				tmp = pt->prev;
				if (tmp)
					tmp->next = trav;
				pt->next = trav->next, pt->prev = trav;
				if (trav->next)
					trav->next->prev = pt;
				trav->prev = tmp;
				trav->next = pt, flippy = 0;
				if (tmp == NULL)
					*list = trav;
				print_list(*list);
			}
			if (flippy)
				trav = trav->prev;
			if (!flippy)
				trav = pt;
			pt = trav->prev;
		}
		oloop = oloop->next;/* next node of linked list */
	}
}
