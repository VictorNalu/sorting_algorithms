#include <stdio.h>
#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the pointer to the head of the list
* @current: Current node
*/
void swap_nodes(listint_t **list, listint_t *current)
{
	if (current->prev)
		current->prev->next = current->next;
	else
		*list = current->next;
	if (current->next)
		current->next->prev = current->prev;
	current->next = current->prev;
	current->prev = current->prev->prev;
	current->next->prev = current;
	if (current->prev)
		current->prev->next = current;
}
/**
* forward_pass - Executes one pass of forward
* iteration of the cocktail shaker sort
* @list: Pointer to the pointer to the head of the list
* @current: Current node
* @end: End node
*
* Return: 1 if elements were swapped, 0 otherwise
*/
int forward_pass(listint_t **list, listint_t *current, listint_t *end)
{
	int swapped = 0;

	while (current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->next;
	}

	return (swapped);
}

/**
* backward_pass - Executes one pass of backward
* iteration of the cocktail shaker sort
* @list: Pointer to the pointer to the head of the list
* @current: Current node
* @start: Start node
*
* Return: 1 if elements were swapped, 0 otherwise
*/
int backward_pass(listint_t **list, listint_t *current, listint_t *start)
{
	int swapped = 0;

	while (current->prev != start)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->prev;
	}

	return (swapped);
}


/**
* cocktail_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Cocktail shaker sort algorithm.
* @list: Pointer to the pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	int swapped;

	listint_t *start, *end, *current;

	do {
		swapped = 0;
		start = *list;
		end = NULL;
		current = start;

		swapped |= forward_pass(list, current, end);

		if (!swapped)
			break;

		end = current;
		swapped |= backward_pass(list, current, start);

	} while (swapped);
}
