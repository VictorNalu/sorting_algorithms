#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start;
    listint_t *end;
    listint_t *current;
    int swapped;
	
	if (list == NULL || *list == NULL)
		return;	

	do {
		swapped = 0;
		start = *list;
		end = NULL;
		current = start;

		while (current->next != end) {
			if (current->n > current->next->n) {
				if (current->prev)
					current->prev->next = current->next;
				else
					*list = current->next;
				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;
				if (current->next)
					current->next->prev = current;

				swapped = 1;
				print_list(*list);
			} else {
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		end = current;

		while (current->prev != start) {
			if (current->n < current->prev->n) {
				if (current->next)
					current->next->prev = current->prev;
				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->next->prev = current;
				if (current->prev)
					current->prev->next = current;

				swapped = 1;
				print_list(*list);
			} else {
				current = current->prev;
			}
		}

		start = current->next;

	} while (swapped);
}
